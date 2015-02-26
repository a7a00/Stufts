#include <stdio.h>
#include "compress40.h"
#include "pnm.h"

#define A2 A2Methods_UArray2  

int denominator = 1; /*FAIL SAFE VALUE*/

struct rgbValue
{
	float r;
	float g;
	float b;
};

struct componentValue
{
	float y;
	float pb;
	float pr;
};

struct coefficients
{
	float a;
	float b;
	float c;
	float d;
	float pr;
	float pb;
};

struct intCoefficients
{
	int a;
	int b;
	int c;
	int d;
	int pr;
	int pb;
};

extern void compress40(FILE *input)
{
	A2 image = readImage(input);
	rgbToComponent(image);
	compressArray(image);
	pixelsToWords(image);
	writeFile(*image);
}

extern void compress40(FILE *input)
{
	printf("Sorry! Not implemented yet. Come back later!\n");
}

extern A2 readImage(FILE *fp)
{
	
	denominator = (Pnm_ppmread(fp, uarray2_methods_plain))->denominator;
	return (Pnm_ppmread(fp, uarray2_methods_plain))->pixels;
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
		for(int col = 0; col < wuarray2_methods_plain->width(*array);
			col++)
		{
			componentValue *component = uarray2_methods_plain->
				at(temp, row, col);
			rgbValue *rgb = uarray2_methods_plain->at(array,
				row, col);
			float r = (float)(rgb->red / denominator);
			float g = (float)(rgb->green / denominator);
			float b = (float)(rgb->blue / denominator);
			component -> y = (0.299 * r + 0.587 * g + 0.114 * b);
			component -> pb = (-0.168736 * r - 0.331264 * g +
				0.5 * b);
			component -> pr = (0.5 * r - 0.418688 * g -
				0.081312 * b);
		}
	}
	uarray2_methods_plain->free(array);
	array = &temp;
}

extern void compressArray(A2 *array)
{
	A2 temp = uarray2_methods_plain->new(
		(uarray2_methods_plain->width(*array)) / 2,
		(uarray2_methods_plain->height(*array)) / 2,
		sizeof(coefficients));
	A2 compressed = uarray2_methods_plain->new(
		(uarray2_methods_plain->width(*array)) / 2,
		(uarray2_methods_plain->height(*array)) / 2,
		sizeof(intCoefficients));
	for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
	{
		for(int col = 0; col < uarray2_methods_plain->width(*array);
			col++)
		{
			if(row % 2 == 0 && col % 2 == 0)
			{
				/*Create variables*/
				coefficients *tempCoefficients;
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
            			tempIntCoefficient->pb =
					Arith40_index_of_chroma
						(tempCoefficients->pb);
            			tempIntCoefficient->pr =
					Arith40_index_of_chroma
						(tempCoefficients->pr);
			}
		}
	}
	uarray2_methods_plain->free(array);
	array = &compressed;
}

extern void pixelsToWords(A2 *array)
{
	A2 words = uarray2_methods_plain->new
		(uarray2_methods_plain->width(*array),
		uarray2_methods_plain->height(*array).
		sizeof(uint64_t));	
	for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
	{
		for(int col = 0; col < uarray2_methods_plain->width(*array);
			col++)
		{
			uint64_t *temp = uarray2_methods_plain->at
				(words, row, col);
			*temp = Bitpack_newu(*temp, 9, 23,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->a);
			*temp = Bitpack_news(*temp, 5, 18,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->b);
			*temp = Bitpack_news(*temp, 5, 13,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->c);
			*temp = Bitpack_news(*temp, 5, 8,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->d);


			*temp = Bitpack_newu(*temp, 4, 4,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->pb);
			*temp = Bitpack_newu(*temp, 4, 0,
				(uint64_t)(uarray2_methods_plain->at
					(*array, i, j)->pr);
		}
	}
	uarray2_methods_plain->free(array);
	array = &words;
}

extern void writeFile(A2 array) /*No need for a pointer here*/
{
	printf("COMP40 Compressed image format 2\n%u %u",
		uarray2_methods_plain->width(array),
			uarray2_methods_plain->height(array));	
	for(int row = 0; row < uarray2_methods_plain->height(*array); row++)
	{
		for(int col = 0; col < uarray2_methods_plain->width(*array);
			col++)
		{
			for(int i = 0; i < 4; i++)
			{
				putchar(Bitpack_gets(*temp_uint, 8, 8*(3-i)));
			}
		}
	}
}

extern float confineToBounds(float i, float lower, float upper)
{
	if(i < lower) return lower;
	if(i > upper) return upper;
	return i;
}
