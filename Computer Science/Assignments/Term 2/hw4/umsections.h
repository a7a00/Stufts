#ifndef UMSECTIONS_INCLUDED
#define UMSECTIONS_INCLUDED
/* Full documentation for this interface is at http://tinyurl.com/2uwhhtu */

#include <stdint.h>
#include <stdio.h>

#define T Umsections_T
typedef struct T *T;  
  /* A value of type T represents a nonempty *sequence* of named sections.
     Each section contains a sequence of Universal Machnine words.
     In addition, each value of type T identifies one section in 
     the sequence as the 'current' section, and a value of type T
     encapsulates an error function.
  */

/* Callers of procedures in this interface need *not* provide
   long-lived pointers to strings.  Callers may reuse string memory
   as soon as the call returns. */

T Umsections_new(const char *section, 
            int (*error)(void *errstate, const char *message),
            void *errstate);
     /* Create a new assembler which emits into the given section.
        The error function, which is called in case of errors,
        must not return.  
     */
void Umsections_free(T *asmp);  // destroy an old assembler
int Umsections_error(T asm, const char *msg);
  /* call the assembler's error function, using the error state
     passed in at creation time */
void Umsections_section(T asm, const char *section);
  /* start emitting to the named section */
typedef uint32_t Umsections_word; // Universal Machine word
void Umsections_emit_word(T asm, Umsections_word data);
  /* Emit a word into the current section */
void Umsections_map(T asm, void apply(const char *name, void *cl), void *cl);
  /* for each section name S in the sequence in 'asm', in order,
     call apply(S, cl) */
int Umsections_length(T asm, const char *name);
  /* if 'name' is a named section in asm, return the number of words
     in that section; otherwise call asm's error function */
Umsections_word Umsections_getword(T asm, const char *name, int i);
  /* Return the word numbered 'i' from the section with the given name.
     The first word is numbered 0.
     If there is no section with the given name, or if i is out of bounds,
     call asm's error function. */
void Umsections_putword(T asm, const char *name, int i, Umsections_word w);
  /* In the section with the given name, replace word 'i' with 'w'.
     If there is no section with the given name, or if i is out of bounds,
     call asm's error function. */
void Umsections_write(T asm, FILE *output); 
  /* Write the contents of each section stored in asm,
     in the order in which they appear in asm's sequence.
     Write the words to file 'output' in UM format.
  */

#undef T
#endif
