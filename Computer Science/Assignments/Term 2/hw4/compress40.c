#include <stdio.h>
#include "pnmrdr.h"
#include "uarray2b.h" 

extern void compress40(FILE *input)
{
	uarray2b_T image = readImage(input);
	trimImage(input);
	rgbToComponent(input);
}

extern void decompress40(FILE *input)
{
	
}

extern uarray2b_T readImage()
