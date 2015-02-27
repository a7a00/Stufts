/*
 *      uarray2.h
 *      By Sartrapat Saengcharoentrakul & Nga Pham
 *      Assignment 2
 *
 *      This is the interface of uarray2.h to support 2 dimensional unboxed
 *      array that can store any data type. The only condition is that all the
 *      elements must have the same size.
 *
 */

#ifndef UARRAY2_INCLUDED 
#define UARRAY2_INCLUDED

#define T UArray2_T

typedef struct T *T;

/* Creates an unboxed array of width and height, each with a memory allocation
 * of size */
extern T UArray2_new (int width, int height, int size);

/* Free the unboxed array */
extern void UArray2_free(T *array);

/* Return the height of the unboxed array */
extern int UArray2_height(T array);

/* Return the width of the unboxed array */
extern int UArray2_width(T array);

/* Return the size of each element in the unboxed array */
extern int UArray2_size(T array);

/* Return the pointer to the element at that column and row */
extern void *UArray2_at(T array, int col, int row);

/* Loops the array row by row and call the apply function on each element */
extern void UArray2_map_row_major(T uarray2,
                                  void apply(int col, int row, T uarray2,
                                                  void *p1, void *p2),
                                  void *c1);

/* Loops through the array column by column and call the apply function on
 * each element */
extern void UArray2_map_col_major(T uarray2,
                                  void apply(int col, int row, T uarray2,
                                                  void *p1, void *p2),
                                  void *c1);

#undef T 
#endif 
