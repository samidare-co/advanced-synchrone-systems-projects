/* --- Generated the 18/12/2024 at 20:44 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c reset_counter.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reset_counter.h"

void Reset_counter__reset_counter_reset(Reset_counter__reset_counter_mem* self) {
  self->v = 0;
}

void Reset_counter__reset_counter_step(int reset_bool,
                                       Reset_counter__reset_counter_out* _out,
                                       Reset_counter__reset_counter_mem* self) {
  
  int v_1;
  int c;
  v_1 = (self->v+1);
  if (reset_bool) {
    c = 0;
  } else {
    c = v_1;
  };
  _out->counter = c;
  self->v = _out->counter;;
}

