/* --- Generated the 18/12/2024 at 23:55 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c automaton.ept --- */

#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "automaton_types.h"
typedef struct Automaton__automate_mem {
  int v_32;
  int v_30;
  int v_28;
  int v_24;
  int v_22;
  int v_20;
  Automaton__astate sprev;
} Automaton__automate_mem;

typedef struct Automaton__automate_out {
  int accept;
} Automaton__automate_out;

void Automaton__automate_reset(Automaton__automate_mem* self);

void Automaton__automate_step(Automaton__alpha l,
                              Automaton__automate_out* _out,
                              Automaton__automate_mem* self);

#endif // AUTOMATON_H
