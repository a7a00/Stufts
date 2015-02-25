/*
 *      UArray2.c
 *      By Alex Gould & Nga Pham
 *      Assignment 2
 *
 *      Summary: This is the implementation of UArray2 (2D unboxed array) based
 *      on Hanson's unboxed array.
 *
 *      Note: Assertion will be called when information are to be obtained from
 *      an empty UArray2 or out of the bounds of the array.
 *
 */

#include "uarray.h"
#include <stddef.h>
#include <string.h>
#include "uarray2.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "except.h"
#include "mem.h"



#define T UArray2_T

struct T {
        int width;
        int height;
        UArray_T twoDArray;
};

extern T UArray2_new (int width, int height, int size)
{
        T uarray2;
        uarray2 = malloc( sizeof(*uarray2) );

        assert(uarray2);

        uarray2->width = width;
        uarray2->height = height;
        uarray2->twoDArray = UArray_new(width * height, size);

        return uarray2;

}


extern void UArray2_free(T *uarray2)
{

        UArray_free( &((*uarray2)->twoDArray) );
        FREE(*uarray2);
        uarray2 = NULL;
}


extern int UArray2_height(T uarray2)
{
        assert(uarray2);
        return uarray2->height;
}


extern int UArray2_width(T uarray2)
{
        assert(uarray2);
        return uarray2->width;
}


extern int UArray2_size(T uarray2)
{
        assert(uarray2);
        return UArray_size(uarray2->twoDArray);
}


extern void *UArray2_at(T uarray2, int col, int row)
{     
        assert(uarray2);
        
        UArray2_height(uarray2);
        
        assert(col >= 0 && col < uarray2->width);
        assert(row >= 0 && row < uarray2->height);

        int index = row * (uarray2->width) + col;
        
        return UArray_at(uarray2->twoDArray, index);
}


extern void UArray2_map_row_major(T uarray2,
                void apply(int col, int row, T uarray2,
                                void *p1, void *p2),
                                void *c1)
{
        assert(uarray2);
        assert(apply);

        for (int i = 0; i < uarray2->height; i++) {
                for (int j = 0; j < uarray2->width; j++) {
                        apply(j, i, uarray2, UArray2_at(uarray2, j, i), c1);
                }
        }
}


extern void UArray2_map_col_major(T uarray2,
                void apply(int col, int row, T uarray2,
                                void *p1, void *p2),
                                void *c1)

{
        assert(uarray2);
        assert(apply);

        for (int j = 0; j < uarray2->width; j++) {
                for (int i = 0; i < uarray2->height; i++) {
                        apply(j, i, uarray2, UArray2_at(uarray2, j, i), c1);
                }
        }
}
