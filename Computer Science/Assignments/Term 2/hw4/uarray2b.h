#ifndef UARRAY2B_INCLUDED
#define UARRAY2B_INCLUDED

#define T UArray2b_T
typedef struct T *T;

/* new blocked 2d array: blocksize = square root of # of cells in block */
extern T    UArray2b_new (int width, int height, int size, int blocksize);

/* new blocked 2d array: blocksize as large as possible provided
 * block occupies at most 64KB (if possible)
 */
extern T    UArray2b_new_64K_block(int width, int height, int size);

extern void  UArray2b_free  (T *array2b);

extern int   UArray2b_width (T array2b);
extern int   UArray2b_height(T array2b);
extern int   UArray2b_size  (T array2b);
extern int   UArray2b_blocksize(T array2b);

/* return a pointer to the cell in column i, row j;
 * index out of range is a checked run-time error
 */
extern void *UArray2b_at(T array2b, int i, int j);

/* visits every cell in one block before moving to another block */
extern void  UArray2b_map(T array2b, 
                          void apply(int i, int j, T array2b,
                                     void *elem, void *cl), 
                          void *cl);

/* 
 * it is a checked run-time error to pass a NULL T
 * to any function in this interface 
 */

#undef T
#endif
