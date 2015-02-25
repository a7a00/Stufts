#include "a2methods.h"

#define A2 A2Methods_UArray2
#define Mapfun A2Methods_mapfun
A2 rotate_cw (A2Methods_T m, A2 a, Mapfun map); /* clockwise 90 degrees */
A2 rotate_ccw(A2Methods_T m, A2 a, Mapfun map); /* counterclockwise 90  */
A2 rotate_180(A2Methods_T m, A2 a, Mapfun map); /* 180 degrees          */
#undef A2
#undef Mapfun
