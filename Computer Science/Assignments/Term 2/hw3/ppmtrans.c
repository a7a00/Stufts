/*
 *      ppmtrans.c
 *      By Nga Pham & Alex Gould
 *      Assignment 3
 *      
 *      //TODO for Alex :)) 
 *      Summary: This is the implementation of a2plain.h. Takes in a pnm
 *      image file from stdin or file entered as an arg. Exits with exit(0)
 *      if the sudoku table is solved, or else it will exit with exit(1).
 *
 *      Invariant: For a valid solved sudoku puzzle, there should be no
 *      duplication of any number in a row, a column or a submap of a table.
 *
 *      Notes: Exits the program when more than one argument is entered or an
 *      invalid sudoku table is entered.
 *
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "assert.h"
#include "a2methods.h"
#include "a2plain.h"
#include "a2blocked.h"
#include "pnm.h"

typedef A2Methods_UArray2 A2;
A2Methods_T methods;   

typedef enum
{
	true,
	false
} bool;


Pnm_ppm rotatePic(int degrees, Pnm_ppm picture);
Pnm_ppm flipPic(bool horizontal, Pnm_ppm picture);
Pnm_ppm transposePic(Pnm_ppm picture);
Pnm_ppm createPPM(Pnm_ppm picture, A2 newPic, int width, int height);
void transpose(int i, int j, A2 array, void *elem, void *cl);
void reverseRows(int i, int j, A2 array, void *elem, void *cl);
void reverseCols(int i, int j, A2 array, void *elem, void *cl);


static void usage(const char *progname)
{
	fprintf(stderr, "Usage: %s [-rotate <angle>] "
			"[-{row,col,block}-major] "
			"[-flip {horizontal, vertical}]"
			"[-transpose] [filename]\n",
			progname);
	exit(1);
}


int main(int argc, char *argv[])
{
	/* what operations are requested */
	int i;
	int rotation = -1;      
	bool flip = false;
	bool transpose = false;
	bool horizontal = false;

	/* default to UArray2 methods */
	methods = uarray2_methods_plain;
	assert(methods);

	/* default to best map */
	A2Methods_mapfun *map = methods->map_default;
	assert(map);

#define SET_METHODS(METHODS, MAP, WHAT) do {                            \
	methods = (METHODS);                                    \
	assert(methods != NULL);                                \
	map = methods->MAP;                                     \
	if (map == NULL) {                                      \
		fprintf(stderr, "%s does not support "          \
				WHAT "mapping\n",               \
				argv[0]);                               \
		exit(1);                                        \
	}                                                       \
} while (0)


	for (i = 1; i < argc; i++) {
                
		if (!strcmp(argv[i], "-row-major")) {
			SET_METHODS(uarray2_methods_plain, map_row_major,
					"row-major");                       
		} else if (!strcmp(argv[i], "-col-major")) {
			SET_METHODS(uarray2_methods_plain, map_col_major,
					"column-major");                        
		} else if (!strcmp(argv[i], "-block-major")) {
			SET_METHODS(uarray2_methods_blocked, map_block_major,
					"block-major");   
                                        
                /* If ROTATION is requested */
		} else if (!strcmp(argv[i], "-rotate")) {
			if (!(i + 1 < argc)) {      /* no rotate value */
				usage(argv[0]);
			}
			char *endptr;
			rotation = strtol(argv[++i], &endptr, 10);
			if (!(rotation == 0 || rotation == 90
                                || rotation == 180 || rotation == 270)) {
				fprintf(stderr, "Rotation must be "
						"0, 90 180 or 270\n");
				usage(argv[0]);
			}
			if (!(*endptr == '\0')) {    /* Not a number */
				usage(argv[0]);
			}

                /* if FLIP is requested */
		} else if(!strcmp(argv[i], "-flip")) {
			flip = true;   
			char *endptr = argv[++i];
			if (!(i + 1 < argc)) {          /* no flip value */
				usage(argv[0]);
			}
			if(strcmp(endptr, "horizontal") &&
					strcmp(endptr, "vertical"))
			{
				fprintf(stderr, "Flip must be horizontal "
						"or vertical\n");
				usage(argv[0]);
			}
			if(!strcmp(/*argv[++i]*/endptr, "horizontal"))
			{
				horizontal = true;
			}

                /* if TRANSPOSE is requested */
		} else if(!strcmp(argv[i], "-transpose")) {
			transpose = true;
                        
		} else if (*argv[i] == '-') {
			fprintf(stderr, "%s: unknown option '%s'\n", argv[0],
					argv[i]);
                                        
		} else if (argc - i > 1) {
			fprintf(stderr, "Too many arguments\n");
			usage(argv[0]);
                        
		} else {
			break;
		}
	}

        /* Read in the file */
        FILE *fp;
        if((fp = fopen(argv[argc-1], "rb")) == NULL)
        {
                fp = stdin;
        }
        
        Pnm_ppm picture = Pnm_ppmread(fp, methods);
        
        /* Call appropriate transformation */
        if (rotation != -1)
        {
                picture = rotatePic(rotation, picture);
        } 
        
        if (flip == true) {
                
                picture = flipPic(horizontal, picture);
        } 
        
        if (transpose == true) {
                
                picture = transposePic(picture);   
        }
        
        Pnm_ppmwrite(stdout, picture);
        
        Pnm_ppmfree(&picture);
        
        if (fp != stdin) fclose(fp);

}

/* Rotate the picture by the given degree, return transformed picture 
 */
Pnm_ppm rotatePic(int degrees, Pnm_ppm picture)
{
        assert(picture);
        assert(degrees % 90 == 0);

        /* Get the information of the original picture */
        int height = picture->methods->height(picture->pixels);
        int width = picture->methods->width(picture->pixels);
        int size = picture->methods->size(picture->pixels);
        
        /* Height and width after transformation */
        int newWidth;
        int newHeight;
        
        /* Buffer A2 for transformation */
        A2 newPic = NULL;
        A2 tempPic = NULL;  

        /* Rotate 0 */
        if(degrees == 0)
        {
                return picture;
        }

        /* Rotate 90: transpose then reverse rows */
        if(degrees == 90) 
        {
                /* transpose */
                tempPic = methods->new(height, width, size);
                methods->map_default(picture->pixels, transpose, tempPic);

                /* reverse each row */
                newPic = methods->new(height, width, size);
                methods->map_default(tempPic, reverseRows, newPic);
                
                newWidth = height;
                newHeight = width;               
        }
        
        /* Rotate 180: reverse rows then reverse columns */
        else if(degrees == 180)
        {
                /* reverse each row */
                tempPic = methods->new(width, height, size);
                methods->map_default(picture->pixels, reverseRows, tempPic);
               
                /* reverse each column */
                newPic = methods->new(width, height, size);
                methods->map_default(tempPic, reverseCols, newPic);
                
                newWidth = width;
                newHeight = height;
        }
   
        /* Rotate 270: transpose then reverse columns */
        else if(degrees == 270)
        {
                /* transpose */
                tempPic = methods->new(height, width, size);
                methods->map_default(picture->pixels, transpose, tempPic);
               
                /* reverse each column */
                newPic = methods->new(height, width, size);
                methods->map_default(tempPic, reverseCols, newPic);
                
                newWidth = height;
                newHeight = width;
        }
        
        methods->free(&tempPic);
        
        /* create new PPM after transformation */
        return createPPM(picture, newPic, newWidth, newHeight);        
}


/* Mirror the picture horizontally or vertically 
 */
Pnm_ppm flipPic(bool horizontal, Pnm_ppm picture)
{
        assert(picture);
        assert(horizontal == true || horizontal == false);

        /* Get the information of the original picture */        
        int height = picture->methods->height(picture->pixels);
        int width = picture->methods->width(picture->pixels);
        int size = picture->methods->size(picture->pixels);
        
        /* Buffer A2 for transformation */
        A2 newPic = methods->new(width, height, size);  

        
        if (horizontal == true) /* Flip horizontal */
        {
                methods->map_default(picture->pixels, reverseRows, newPic);    
        
        } else {                /* Flip vertical */
                
                methods->map_default(picture->pixels, reverseCols, newPic); 
        }
       
        return createPPM(picture, newPic, width, height);

}


/* Transpose given picture 
 */
Pnm_ppm transposePic(Pnm_ppm picture)
{
        assert(picture);

        /* Get the information of the original picture */       
        int height = picture->methods->height(picture->pixels);
        int width = picture->methods->width(picture->pixels);
        int size = picture->methods->size(picture->pixels);
       
        /* Map and transpose */
        A2 newPic = methods->new(height, width, size);
        methods->map_default(picture->pixels, transpose, newPic);

        return createPPM(picture, newPic, height, width);
        
}


/* Created new PPM of transformed picture by altering old PPM's properties 
 */
Pnm_ppm createPPM(Pnm_ppm picture, A2 newPic, int newWidth, int newHeight)
{
        /* Free old array of pixels */
        picture->methods->free(&picture->pixels);
        
        picture -> pixels = newPic;
        picture -> width = newWidth;
        picture -> height = newHeight;

        return picture;
   
}


/* Apply function: transpose
 * Set newArray[i][j] to be oldArray[j][i]
 */
void transpose(int i, int j, A2 array, void *elem, void *cl)
{
        (void) array;
        
        /* Elem is the value at [i][j] of old array */
        /* cl points to new array */
        
        *(Pnm_rgb)methods->at((A2)cl, j, i) = *((Pnm_rgb) elem);
}


/* Apply function: reverse each row */
void reverseRows(int i, int j, A2 array, void *elem, void *cl)
{
        (void) array;
        
        /* Mirror col value horizontally */
        int col = methods->width((A2)cl) - 1 - i;
        int row = j;
        
        /* Elem is oldArray at index i, j; cl is new array */
        *(Pnm_rgb) methods->at((A2)cl, col, row) = *((Pnm_rgb) elem);
}


/* Apply function: reverse each column */
void reverseCols(int i, int j, A2 array, void *elem, void *cl)
{
        (void) array;
        
        /* Mirror row value vertically */
        int col = i;
        int row = methods->height((A2)cl)-1-j;

        *(Pnm_rgb) methods->at((A2)cl, col, row) = *((Pnm_rgb) elem);
}
