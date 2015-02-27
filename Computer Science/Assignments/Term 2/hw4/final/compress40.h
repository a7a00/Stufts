#include <stdio.h>
#include "a2methods.h"

#define A2 A2Methods_UArray2  

/*
 * The two functions below are functions you should implement.
 * They should take their input from the parameter and should
 *  write their output to stdout
 */

extern void compress40  (FILE *input);  /* reads PPM, writes compressed image */
extern void decompress40(FILE *input);  /* reads compressed image, writes PPM */

extern A2 readImage(FILE *fp);
extern void rgbToComponent(A2 *array);
extern void compressArray(A2 *array);
extern void pixelsToWords(A2 *array);
extern void writeFile(A2 array);

extern A2 readCompressed();//FILE *fp);
extern void wordsToPixels(A2 *array);
//extern void decompressArray(A2 *array);
extern void componentToRgb(A2 *array);
extern void writeDecompressed(A2 array);
