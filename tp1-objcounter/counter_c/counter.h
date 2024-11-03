/* --- Generated the 1/11/2024 at 0:0 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c counter.ept --- */

#ifndef COUNTER_H
#define COUNTER_H

#include "counter_types.h"
typedef struct Counter__counter_mem {
  int mem_cnt;
} Counter__counter_mem;

typedef struct Counter__counter_out {
  int cnt;
} Counter__counter_out;

void Counter__counter_reset(Counter__counter_mem* self);

void Counter__counter_step(Counter__counter_out* _out,
                           Counter__counter_mem* self);

#endif // COUNTER_H
