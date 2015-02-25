#ifndef PNMRDR_INCLUDED
#define PNMRDR_INCLUDED
#include "except.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define T Pnmrdr_T
typedef struct T *T;

extern const Except_T Pnmrdr_Badformat;   /* raised when not a pnm file   */
extern const Except_T Pnmrdr_Count; /* raised when wrong number of          */
                                    /* pixels read                          */
typedef enum { Pnmrdr_bit = 1, Pnmrdr_gray = 2, Pnmrdr_rgb = 3 } 
        Pnmrdr_maptype;

typedef struct {
        Pnmrdr_maptype type;
        unsigned width, height;
        unsigned denominator;     /* (gray & color) used to scale integers  */
                                  /* to be read                             */
} Pnmrdr_mapdata;

extern char *Pnmrdr_maptype_names[];

extern T Pnmrdr_new(FILE *fp);            /* raises Pnmrdr_Badformat      */
extern Pnmrdr_mapdata Pnmrdr_data(T rdr);
extern unsigned Pnmrdr_get(T rdr);  /* raises Pnmrdr_Count if exhausted     */
extern void Pnmrdr_free(T *rdr);    /* raises Pnmrdr_Count unless either    */
                                    /* no pixels or all pixels were read    */
#undef T
#endif
