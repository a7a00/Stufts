#ifndef PNM_INCLUDED
#define PNM_INCLUDED
#include <stdio.h>
#include <stdint.h>

#include <except.h>

#include <a2methods.h>

// functions in this interface use only the 'new', 'free',
// 'cell', and 'map_default' methods

// every function in this interface uses the (x, y) coordinate system,
// which is the same as the (col, row) or (width, height) system.

typedef struct Pnm_rgb { // colored pixel (scaled integers)
  unsigned red, green, blue;
} *Pnm_rgb;

typedef struct Pnm_ppm {
  unsigned width, height, denominator;
  A2Methods_UArray2 pixels; // 2D array with element type 'struct Pnm_rgb'
  const struct A2Methods_T *methods; // used to operate on 'pixels' field
} *Pnm_ppm;
   // clients may read 'methods, but to mutate 'methods' or any 
   // field of 'methods' is an UNCHECKED run-time error

extern const Except_T Pnm_Badformat; // raised by ppmread when not a pnm file

Pnm_ppm Pnm_ppmread(FILE *fp, A2Methods_T methods);
  /* Read a file using the given methods and return a pixmap
     containing a 2D array of the type returned by 'methods->new'.
     'methods' field of the result is the same as the argument.
     Raises Pnm_Badformat if not given a proper PNM file.
     methods are not copied, so caller must ensure they live as long as the pixmap.
   */

void Pnm_ppmwrite(FILE *fp, Pnm_ppm pixmap);
  /* Write 'pixmap' to a file.  If 'pixmap' is empty, it's a checked 
     run-time error. */

void Pnm_ppmfree(Pnm_ppm *ppmp);
  /* Free pixmap pointed to by ppmp. Does not free methods. */

#endif
