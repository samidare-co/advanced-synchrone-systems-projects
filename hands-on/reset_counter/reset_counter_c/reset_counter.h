/* --- Generated the 18/12/2024 at 20:44 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c reset_counter.ept --- */

#ifndef RESET_COUNTER_H
#define RESET_COUNTER_H

#include "reset_counter_types.h"
typedef struct Reset_counter__reset_counter_mem {
  int v;
} Reset_counter__reset_counter_mem;

typedef struct Reset_counter__reset_counter_out {
  int counter;
} Reset_counter__reset_counter_out;

void Reset_counter__reset_counter_reset(Reset_counter__reset_counter_mem* self);

void Reset_counter__reset_counter_step(int reset_bool,
                                       Reset_counter__reset_counter_out* _out,
                                       Reset_counter__reset_counter_mem* self);

#endif // RESET_COUNTER_H
