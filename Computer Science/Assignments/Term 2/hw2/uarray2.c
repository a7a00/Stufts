#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "uarray2.h"
#include "mem.h"

#define T UArray2_T
#define length width

struct UArray2_T {
        int height;
        int width;
        int size;
        char *elements;
};

T UArray2_new (int height, int width, int size) 
{
        T array;
        NEW (array);
        if (width*height > 0)
	{
		UArray2_init(array, height, width, size,
			CALLOC(width*height, size));
	}
	else 
		UArray2_init(array, height, width, size, NULL);
	return array;
}

void UArray2_init(T uarray2, int height, int width, int size, 
                        void *elements);
{
	assert(uarray2);
	assert((elements > 0) && (width > 0) || (width == 0 &&
		elements == NULL));
	assert(size > 0);
	uarray2->width = width;
	uarray2->height = height;
	uarray2->size = size;
	if(width > 0) uarray2->elements = elements;
	else uarray2->elements = NULL;
}

void UArray2_free (T *uarray2)
{
	assert(uarray2 && *uarray2);
	FREE((*uarray)->elements);
	FREE(*uarray);
}

void *UArray2_at (T uarray2, int row, int col)
{
	assert(uarray);
	assert(row >= 0 && row < uarray2->width);	
	assert(col >= 0 && col < uarray2->height);
	int rowJumps = uarray2->size * uarray2->width * row;
	int colJumps = uarray2->size * col;
	return uarray2->elements + rowJumps + colJumps;
}

int UArray2_width (T uarray2)
{
	assert(uarray2);
	return uarray2->width;
}

int UArray2_height (T uarray2)
{
	assert(uarray2);
	return uarray2->height;
}

int UArray2_size (T uarray2)
{
	assert(uarray2);
	return uarray2->size;
}

void UArray2_map_row_major(T uarray2, void apply(int element,
                        int value, void *cl), void *cl)
{
	assert(uarray2);
	int index;
	int total = uarray2->width * uarray2->height;
	for(index = 0; index < total; index += uarray2->size)
		apply(index, uarray2->elements + index, cl);
}

void UArray2_map_col_major(T uarray2, void apply(int element,
                        int value, void *cl), void *cl)
{
	assert(uarray2);
	int index;
	int total = uarray2->width * uarray2->height;
	int i, j;
	int aWholeRow = uarray2->width * uarray2->size;
	for(i = 0; i < uarray2->width; i += size)
	{
		for(j = 0; j < uarray2->height j += aWholeRow)
		{
			apply((i + j), uarray2->elements + i + j, cl);
		}
	}
}
