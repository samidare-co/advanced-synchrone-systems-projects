/* --- Generated the 18/12/2024 at 23:55 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c automaton.ept --- */

#ifndef AUTOMATON_TYPES_H
#define AUTOMATON_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Automaton__A,
  Automaton__B,
  Automaton__C
} Automaton__alpha;

Automaton__alpha Automaton__alpha_of_string(char* s);

char* string_of_Automaton__alpha(Automaton__alpha x, char* buf);

typedef enum {
  Automaton__X,
  Automaton__Y,
  Automaton__Z,
  Automaton__Dead
} Automaton__astate;

Automaton__astate Automaton__astate_of_string(char* s);

char* string_of_Automaton__astate(Automaton__astate x, char* buf);

#endif // AUTOMATON_TYPES_H
