/*
 *      uarray2b.c
 *      By Alexander Gould & Nga Pham
 *
 *      From the creators of UArray2.c...
 *      Comes a thrilling new tale of pointers and coordinates
 *      With executive producer Alex Gould and Director Nga Pham.
 *      A story of an array. An array torn apart by innter turmoil.
 *      Blocked from his destiny by evil developers with a finite sized cache.
 *
 *                      _     _      ______     ______
 *                     | |   | |    / ___  \   |  __  \
 *                     | |   | |    \/   | |   | |__/ /
 *                     | |   | |      ___/ /   |  ___ \
 *                     \ \___/ /     /  __/_   | |  /  |
 *                      \_____/     |_______|  |______/
 *
 *                             U2B.C(ONTINUED)
 *
 *      (Copypasta courtesy of Bejamin Lewin and Aaron Kruger, Spring 2014)
 *
 *      Contains implementations of the functions defined in uarray2b.h.
 *      The interface is represented as a UArray2_T, containing smaller
 *      UArray2_T's, each representing a block. The UArray2_T data type
 *      keeps its members close in memory through use of a 1D representation.
 *      For more details, see uarray2.h/c.
 *
 *      Feb 5, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "uarray2b.h"
#define T UArray2b_T

const int SIXTY_FOUR_KB = 65536; /*bytes*/

//typedef struct T *T;

struct T 
{
     int width;
     int height;
     int size;
     int blocksize;
     int WidInBlocks;   /* How many blocks in the width */
     int HgtInBlocks;   /* How many blocks in the height */     
     UArray2_T grid;    /* Contains UArray2_T of blocks */
};


/* New blocked 2d array: blocksize = square root of # of cells in block */
extern T UArray2b_new (int width, int height, int size, int blocksize)
{
        assert(width > 0 && height > 0);
        assert(size > 0 && blocksize > 0);
        
        T uarray2b = malloc(sizeof(*uarray2b));
        
        /* Set given values */
        uarray2b->width = width;
        uarray2b->height = height;
        uarray2b->size = size;
        uarray2b->blocksize = blocksize;
        
        /* Ceil up WidInBlocks to include partically filled blocks */
        uarray2b->WidInBlocks = ceil((double) width/blocksize);
        uarray2b->HgtInBlocks = ceil((double) height/blocksize);
        
        /* Create outer UArray2 */
        uarray2b->grid = UArray2_new(uarray2b->WidInBlocks, 
                                     uarray2b->HgtInBlocks, 
                                     size * blocksize * blocksize);
        
        /* Loop through outer UArray2, at each cell, create inner UArray2 
         * to store elements of a block */
        for (int i = 0; i < uarray2b->WidInBlocks; i++) 
        {
                for (int j = 0; j < uarray2b->HgtInBlocks; j++) 
                {
                        UArray2_T *temp = UArray2_at(uarray2b->grid, i, j);
                        *temp = UArray2_new(blocksize, blocksize, size); 
                }
        }
        
        return uarray2b;
}


/* New blocked 2d array: blocksize as large as possible provided block occupies
 * at most 64KB (if possible) */
extern T UArray2b_new_64K_block(int width, int height, int size) 
{
        assert(width > 0 && height > 0);
        assert(size > 0);
        
        /* Max blocksize possible */
        int blocksize = sqrt(SIXTY_FOUR_KB/size);
        
        return UArray2b_new(width, height, size, blocksize);
}


/* Free array2b */
extern void UArray2b_free (T *array2b)
{
        assert(array2b && *array2b);
        
        /* Loop through outer UArray2 to free every inner UArray2 */
        for (int i = 0; i < (*array2b)->WidInBlocks; i++) 
        {
                for (int j = 0; j < (*array2b)->HgtInBlocks; j++) 
                {
                        UArray2_free(UArray2_at((*array2b)->grid, i, j));
                }
        }
        
        /* Free outer UArray2 and the whole structure */
        UArray2_free(&((*array2b)->grid));
        FREE(*array2b);
}


/* Return the width in cells*/
extern int UArray2b_width (T array2b)
{
        assert(array2b);
        return array2b->width;
}


/* Return the height in cells */
extern int UArray2b_height(T array2b)
{
        assert(array2b);
        return array2b->height;
}


/* Return the size */
extern int UArray2b_size (T array2b)
{
        assert(array2b);
        return array2b->size;
}

/* Return the block size */
extern int UArray2b_blocksize(T array2b)
{
        assert(array2b);
        return array2b->blocksize;
}


/* Return a pointer to the cell in column i, row j; 
 * Index out of range is a checked run-time error */
extern void *UArray2b_at(T array2b, int col, int row)
{
        assert(array2b);
        assert(col >= 0 && col < array2b->width);
        assert(row >= 0 && row < array2b->height);
        
        /* Coordinates in the outer UArray2 */
        int blockcol = col / array2b->blocksize;
        int blockrow = row / array2b->blocksize;
        
        /* Coordinates in the inner UArray2 */
        int colInBlock = col % array2b->blocksize;
        int rowInBlock = row % array2b->blocksize;
        
        /* Find inner UArray2 */
        UArray2_T *temp = UArray2_at(array2b->grid, blockcol, blockrow);  
          
        return UArray2_at(*temp, colInBlock, rowInBlock);
}


/* Visits every cell in one block before moving to another block.
 * It is a checked run-time error to pass a NULL T to any function in this
 * interface */
extern void UArray2b_map(T array2b,
                void apply(int i, int j, T array2b, void *element, void *cl),
                void *cl)
{
        assert(array2b && cl);
        int i, j;
        void *element = NULL; 
        
        for(i = 0; i < array2b->WidInBlocks; i++) 
        {
                for(j = 0; j < array2b->HgtInBlocks; j ++)
                {
                        mapBlock(array2b, array2b->width,
                                array2b->height, element, cl, apply, i, j);
                }
        }
}


/*
 * Should recognize and accomodate partially filled blocks without
 * segfaulting.
 * Blocki and Blockj are indices in the outer UArray2
 */
extern void mapBlock(T array2b, int width, int height, void *element,
                void *cl,
                void apply(int i, int j, T array2b, void *element, void *cl),
                int blocki, int blockj)
{
               
        /* Number of full blocks on the width */
        int fullBlocksWid = width / (array2b->blocksize);

        /* Number of full blocks on the height */
        int fullBlocksHgt = height / (array2b->blocksize);
        
        /* FULL BLOCK */
        if(blocki < fullBlocksWid && blockj < fullBlocksHgt)
        {
                for(int i = 0; i < array2b->blocksize; i++)
                {
                        for(int j = 0; j < array2b->blocksize; j++)
                        {
                                /* Coordinates in terms of cells */
                                int col = i + blocki * (array2b->blocksize);
                                int row = j + blockj * (array2b->blocksize);
                                element = UArray2b_at(array2b, col, row);

                                apply(col, row, array2b, element, cl);
                        }
                }
        }
        
        /* RIGHT BOTTOM CORNER BLOCK */
        else if (blocki == fullBlocksWid && blockj == fullBlocksHgt)
        {       
                for(int i = 0; i < width % array2b->blocksize; i++)
                {
                        for(int j = 0; j < height % array2b->blocksize; j++)
                        {
                                int col = i + blocki * (array2b->blocksize);
                                int row = j + blockj * (array2b->blocksize);
                                element = UArray2b_at(array2b, col, row);

                                apply(col, row, array2b, element, cl);
                        }
                }
        }

        /* RIGHT EDGE PARTIALLY FILLED BLOCK */
        else if(blocki == fullBlocksWid)
        {
                for(int i = 0; i < width % array2b->blocksize; i++)
                {
                        for(int j = 0; j < array2b->blocksize; j++)
                        {
                                int col = i + blocki * (array2b->blocksize);
                                int row = j + blockj * (array2b->blocksize);
                                element = UArray2b_at(array2b, col, row);

                                apply(col, row, array2b, element, cl);
                        }
                }
        }

        // LEFT EDGE PARTIALLY FILLED BLOCK */
        else if(blockj == fullBlocksHgt)
        {
                for(int i = 0; i < array2b->blocksize; i++)
                {
                        for(int j = 0; j < height % array2b->blocksize; j++)
                        {
                                int col = i + blocki * (array2b->blocksize);
                                int row = j + blockj * (array2b->blocksize);
                                element = UArray2b_at(array2b, col, row);

                                apply(col, row, array2b, element, cl);
                        }
                }
        }
}

