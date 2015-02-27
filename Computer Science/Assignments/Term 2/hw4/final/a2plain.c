/*
 *      a2plain.c
 *      By Nga Pham & Alex Gould
 *      Assignment 3
 *      
 *      //TODO for Alex :)) You can maximize your creativity here. TA loves 
 *      your ASCII Arts
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


#include <stdlib.h>
#include <stdio.h>

#include <a2plain.h>
#include "uarray2.h"

#include <assert.h>
// define a private version of each function in A2Methods_T that we implement

typedef A2Methods_UArray2 A2;

static A2Methods_UArray2 new(int width, int height, int size)
{
        return UArray2_new(width, height, size);
}

static A2Methods_UArray2 new_with_blocksize(int width, int height, int size,
                                            int blocksize)
{
        (void)blocksize;
        return UArray2_new(width, height, size);
}

void a2free(A2 *array2p)
{
        UArray2_free((UArray2_T*)array2p);
}

static int width(A2 array2)
{
        assert(array2);
        return UArray2_width(array2);
}

static int height(A2 array2)
{
        assert(array2);
        return UArray2_height(array2);
}

static int size(A2 array2)
{
        assert(array2);
        return UArray2_size(array2);
}

static int blocksize(A2 array2)
{
        assert(array2);
        return 1;
}

static A2Methods_Object *at(A2 array2, int i, int j)
{
        return UArray2_at(array2, i, j);
}

typedef void applyfun(int i, int j, UArray2_T array2, void *elem, void *cl);

static void map_row_major(A2 array2, A2Methods_applyfun apply, void *cl)
{
        UArray2_map_row_major(array2, (applyfun *) apply, cl);
}

static void map_col_major(A2 array2, A2Methods_applyfun apply, void *cl)
{
        UArray2_map_col_major(array2, (applyfun *) apply, cl);
}

struct small_closure {                  // TODO: Hi there, we just copied pasted
        A2Methods_smallapplyfun *apply;
        void *cl;
};

static void apply_small(int i, int j, UArray2_T array2, void *elem, void *vcl)
{
        struct small_closure *cl = vcl;
        (void)i;
        (void)j;
        (void)array2;
        cl->apply(elem, cl->cl);
}

static void small_map_row_major(A2 a2, A2Methods_smallapplyfun apply,
                                  void *cl)
{
        struct small_closure mycl = { apply, cl };
        UArray2_map_row_major(a2, apply_small, &mycl);
}

static void small_map_col_major(A2 a2, A2Methods_smallapplyfun apply,
                                  void *cl)
{
        struct small_closure mycl = { apply, cl };
        UArray2_map_col_major(a2, apply_small, &mycl);
}

static struct A2Methods_T uarray2_methods_plain_struct = {
        new,
        new_with_blocksize,
        a2free,
        width,
        height,
        size,
        blocksize,
        at,
        map_row_major,
        map_col_major,
        NULL,
        map_col_major,
        small_map_row_major,
        small_map_col_major,
        NULL,
        small_map_col_major,
};

A2Methods_T uarray2_methods_plain = &uarray2_methods_plain_struct;
