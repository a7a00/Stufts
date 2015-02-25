#include <stdint.h>

extern const char *Um_disassemble(uint32_t instruction);
/* Returns a string representing the semantics of a UM instruction.
   The caller is responsible for deallocating the string with 
   Mem_free from the CII library */
