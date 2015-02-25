#ifndef UMMACROS_INCLUDED
#define UMMACROS_INCLUDED
/* Full documentation for this interface is at http://tinyurl.com/2uwhhtu */

#include "umsections.h"
#include "um-opcode.h"

typedef enum Ummacros_Op { MOV = LV+1, COM, NEG, SUB, AND, OR } Ummacros_Op;
  /* move, one's complement (~), two's-complement negation (-),
     subtract, bitwise &, bitwise | */

typedef enum Ummacros_Reg { r0 = 0, r1, r2, r3, r4, r5, r6, r7 } Ummacros_Reg;
  /* Represents a UM register number, which several functions in this
     interface expect as arguments. */

void Ummacros_op(Umsections_T asm, Ummacros_Op operator, int temporary,
                 Ummacros_Reg A, Ummacros_Reg B, Ummacros_Reg C);
  /* Emit a macro instruction into 'asm', possibly overwriting temporary
     register. Argument of -1 means no temporary is available.
     Macro instructions include MOV, COM, NEG, SUB, AND, and OR.
     If a temporary is needed but none is available, Umsections_error(). */
void Ummacros_load_literal(Umsections_T asm, int temporary,
                           Ummacros_Reg A, uint32_t k);
  /* Emit code to load literal k into register A. 
     Must work even if k and ~k do not fit in 25 bits---in which
     case temporary register may be overwritten.  Call the
     error function if temporary is needed but is supplied as -1 */
#endif
