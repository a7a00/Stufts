#include <stdio.h>
#include "compress40.h"
#include "arith40.h"
#include "a2methods.h"
#include "a2plain.h"
#include "bitpack.h"
#include "pnm.h"
#include "assert.h"

#define A2 A2Methods_UArray2  

int denominator = 1; /*FAIL SAFE VALUE*/

typedef struct //rgbValue
{
        float r;
        float g;
        float b;
} rgbValue;

typedef struct //componentValue
{
        float y;
        float pb;
        float pr;
} componentValue;

typedef struct //coefficients
{
        float a;
        float b;
        float c;
        float d;
        float pr;
        float pb;
} coefficients;

typedef struct //intCoefficients
{
        int a;
        int b;
        int c;
        int d;
        int pr;
        int pb;
} intCoefficients;

extern void compress40(FILE *input)
{
        A2 image = readImage(input);
        rgbToComponent(&image);
        compressArray(&image);
        pixelsToWords(&image);
        writeFile(image);
}

extern void decompress40(FILE *input)
{
	A2 image = readCompressed(input);
	wordsToPixels(&image);
	componentToRgb(&image);
	writeDecompressed(image);
}

extern A2 readImage(FILE *fp)
{ 
	Pnm_ppm image = (Pnm_ppmread(fp, uarray2_methods_plain));
	denominator = image->denominator;
        return image->pixels;
}

extern void writeDecompressed(A2 array)
{
	struct Pnm_ppm pixmap = {
		.width = uarray2_methods_plain->width(array),
		.height = uarray2_methods_plain->height(array),
		.denominator = 255,
		.pixels = array
	};
	Pnm_ppmwrite(stdout, &pixmap);
}

extern void rgbToComponent(A2 *array)
{
        int width = uarray2_methods_plain->width(*array);
        int height = uarray2_methods_plain->height(*array);
        if(width % 2 != 0) width--;
        if(height % 2 != 0) height--;
        A2 temp = uarray2_methods_plain->new(width, height,
                sizeof(componentValue));
        for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(*array);
                        col++)
                {
                        componentValue *component = uarray2_methods_plain->
                                at(temp, row, col);
                        rgbValue *rgb = uarray2_methods_plain->at(*array,
                                row, col);
                        float r = (float)(rgb->r / denominator);
                        float g = (float)(rgb->g / denominator);
                        float b = (float)(rgb->b / denominator);
                        component -> y = (0.299 * r + 0.587 * g + 0.114 * b);
                        component -> pb = (-0.168736 * r - 0.331264 * g +
                                0.5 * b);
                        component -> pr = (0.5 * r - 0.418688 * g -
                                0.081312 * b);
                }
        }
        uarray2_methods_plain->free(array);
        *array = temp;
}

extern float confineToBounds(float i, float lower, float upper)
{
        if(i < lower) return lower;
        if(i > upper) return upper;
        return i;
}

extern void componentToRgb(A2 *array)
{	
        int width = uarray2_methods_plain->width(*array) * 2;
        int height = uarray2_methods_plain->height(*array) * 2;
        A2 temp = uarray2_methods_plain->new(width, height,
                sizeof(rgbValue));	
        A2 otherTemp = uarray2_methods_plain->new(width, height,
                sizeof(componentValue));
        for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(*array);
                        col++)
                {
			
                        intCoefficients *intcoeffs = uarray2_methods_plain->
                                at(*array, row, col);
                        rgbValue *rgb = uarray2_methods_plain->at(temp,
                                row, col);
			componentValue *component = uarray2_methods_plain->
				at(otherTemp, row, col);
			component->pb = Arith40_chroma_of_index(
				(unsigned)(intcoeffs->pb));	
			component->pr = Arith40_chroma_of_index(
				(unsigned)(intcoeffs->pb));
			if(row % 2 == 0 && col % 2 == 0)
			{
				component->y = intcoeffs->a - 
					intcoeffs->b - intcoeffs->c +
						intcoeffs->d;
			}
			if(row % 2 == 0 && col % 2 == 1)
			{
				component->y = intcoeffs->a - 
					intcoeffs->b + intcoeffs->c -
						intcoeffs->d;
			}
			if(row % 2 == 1 && col % 2 == 0)
			{
				component->y = intcoeffs->a + 
					intcoeffs->b - intcoeffs->c -
						intcoeffs->d;
			}
			if(row % 2 == 1 && col % 2 == 1)
			{
				component->y = intcoeffs->a +
					intcoeffs->b + intcoeffs->c +
						intcoeffs->d;
			}
			rgb->r = 1.0 * component->y + 0.0 *
				component->pb + 1.402 * component->pr;
			rgb->g = 1.0 * component->y - 0.344136 *
				component->pb - 0.714136 * component->pr;
			rgb->b = 1.0 * component->y + 1.772 *
				component->pb + 0.0 * component->pr;
		}
	}
        uarray2_methods_plain->free(otherTemp);
        uarray2_methods_plain->free(array);
        *array = temp;
}

extern void compressArray(A2 *array)
{
        A2 compressed = uarray2_methods_plain->new(
                (uarray2_methods_plain->width(*array)) / 2,
                (uarray2_methods_plain->height(*array)) / 2,
                sizeof(intCoefficients));
        A2 temp = uarray2_methods_plain->new(
                (uarray2_methods_plain->width(*array)) / 2,
                (uarray2_methods_plain->height(*array)) / 2,
                sizeof(coefficients));
        for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(*array);
                        col++)
                {
                        if(row % 2 == 0 && col % 2 == 0)
                        {
                                /*Create variables*/
                                coefficients *tempCoefficients =
                                        uarray2_methods_plain
                                        ->at(temp, row/2, col/2);
                                intCoefficients *tempIntCoefficients =
                                        uarray2_methods_plain
                                        ->at(compressed, row/2, col/2);

                                /*Set them equal to what's there*/
                                componentValue *y1 = uarray2_methods_plain->
                                        at(*array, row, col);
                                componentValue *y2 = uarray2_methods_plain->
                                        at(*array, row+1, col);
                                componentValue *y3 = uarray2_methods_plain->
                                        at(*array, row, col+1);
                                componentValue *y4 = uarray2_methods_plain->
                                        at(*array, row+1, col+1);

                                /*Apply matrix transformation*/
                                tempCoefficients->a =
                                        (y4->y + y3->y + y2->y + y1->y);
                                tempCoefficients->a /= 4.0;
                                tempCoefficients->b =
                                        (y4->y + y3->y - y2->y - y1->y);
                                tempCoefficients->b /= 4.0;
                                tempCoefficients->c =
                                        (y4->y - y3->y + y2->y - y1->y);
                                tempCoefficients->c /= 4.0;
                                tempCoefficients->d =
                                        (y4->y - y3->y - y2->y + y1->y);
                                tempCoefficients->d /= 4.0;
                                tempCoefficients->pr =
                                        (y4->pr + y3->pr + y2->pr + y1->pr);
                                tempCoefficients->pr /= 4.0;
                                tempCoefficients->pb =
                                        (y4->pb + y3->pr + y2->pr + y1->pr);
                                tempCoefficients->pr /= 4.0;

                                /*Keep in bounds*/
                                tempCoefficients->a = confineToBounds
                                        (tempCoefficients->a, 0.0, 1.0);
                                tempCoefficients->b = confineToBounds
                                        (tempCoefficients->b, -0.3, 0.3);
                                tempCoefficients->c = confineToBounds
                                        (tempCoefficients->c, -0.3, 0.3);
                                tempCoefficients->d = confineToBounds
                                        (tempCoefficients->d, -0.3, 0.3);

                                /*Cast and place in new array*/
                                tempIntCoefficients->a =
                                        (int)(tempCoefficients->a * 511);
                                tempIntCoefficients->b =
                                        (int)(tempCoefficients->c * 50);
                                tempIntCoefficients->c =
                                        (int)(tempCoefficients->b * 50);
                                tempIntCoefficients->d =
                                        (int)(tempCoefficients->d * 50);
                                tempIntCoefficients->pb =
                                        Arith40_index_of_chroma
                                        (tempCoefficients->pb);
                                tempIntCoefficients->pr =
                                        Arith40_index_of_chroma
                                        (tempCoefficients->pr);
                        }
                }
        }
        uarray2_methods_plain->free(array);
        *array = compressed;
}

extern void pixelsToWords(A2 *array)
{
        A2 words = uarray2_methods_plain->new
                (uarray2_methods_plain->width(*array),
                uarray2_methods_plain->height(*array),
                sizeof(uint64_t));        
        for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(*array);
                        col++)
                {	
                        uint64_t *temp = uarray2_methods_plain->at
                                (words, row, col);
			intCoefficients *tempCoefficients =
				uarray2_methods_plain->at(*array, row, col); 
                        *temp = Bitpack_newu(*temp, 9, 23,
                                (uint64_t)(tempCoefficients->a));
                        *temp = Bitpack_news(*temp, 5, 18,
                                (uint64_t)(tempCoefficients->b));
                        *temp = Bitpack_news(*temp, 5, 13,
                                (uint64_t)(tempCoefficients->c));
                        *temp = Bitpack_news(*temp, 5, 8,
                                (uint64_t)(tempCoefficients->d));

                        *temp = Bitpack_newu(*temp, 4, 4,
                                (uint64_t)(tempCoefficients->pb));
                        *temp = Bitpack_newu(*temp, 4, 0,
                                (uint64_t)(tempCoefficients->pr));
                }
        }
	uarray2_methods_plain->free(array);
        *array = words;
}

extern void wordsToPixels(A2 *array)
{
        A2 pixels = uarray2_methods_plain->new
                (uarray2_methods_plain->width(*array),
                uarray2_methods_plain->height(*array),
                sizeof(intCoefficients));        
        for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(*array);
                        col++)
                {	
                        uint64_t *temp = uarray2_methods_plain->at
                                (*array, row, col);
			intCoefficients *tempCoefficients =
				uarray2_methods_plain->at(pixels, row, col);
			tempCoefficients->a = Bitpack_gets(*temp, 9, 23);
			tempCoefficients->b = Bitpack_gets(*temp, 5, 18);
			tempCoefficients->c = Bitpack_gets(*temp, 5, 13);
			tempCoefficients->d = Bitpack_gets(*temp, 5, 8);

			tempCoefficients->pb = Bitpack_gets(*temp, 4, 4);
			tempCoefficients->pr = Bitpack_gets(*temp, 4, 0);
                }
        }
        uarray2_methods_plain->free(array);
        *array = pixels;
}

extern void writeFile(A2 array) /*No need for a pointer here*/
{
        printf("COMP40 Compressed image format 2\n%u %u",
                uarray2_methods_plain->width(array),
                        uarray2_methods_plain->height(array));        
        for(int row = 0; row < uarray2_methods_plain->height(array); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(array);
                        col++)
                {
                        for(int i = 0; i < 4; i++)
                        {
                                putchar(Bitpack_gets((uint64_t)(uarray2_methods_plain->at
					(array, row, col)), 8, 8*(3-i)));
                        }
                }
        }
}

extern A2 readCompressed()
{
	unsigned height, width;
	int read = fscanf(stdin, "COMP40 Compressed image format 2\n%u %u",
		&width, &height);
	assert(read == 2);
	int c = getc(stdin);
	assert(c == '\n');
	A2 image = uarray2_methods_plain->new(width,
		height, sizeof(uint64_t));	
        for(int row = 0; row < uarray2_methods_plain->height(image); row++)
        {
                for(int col = 0; col < uarray2_methods_plain->width(image);
                        col++)
                {
                        for(int i = 0; i < 4; i++)
                        {
                                putchar(Bitpack_gets((uint64_t)(uarray2_methods_plain->at
					(image, row, col)), 8, 8*i));
                        }
                }
        }
	return image;
}
