/* --- Generated the 1/11/2024 at 0:0 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c counter.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "counter.h"

void Counter__counter_reset(Counter__counter_mem* self) {
  self->mem_cnt = 0;
}

void Counter__counter_step(Counter__counter_out* _out,
                           Counter__counter_mem* self) {
  
  int v;
  _out->cnt = self->mem_cnt;
  v = (_out->cnt+1);
  self->mem_cnt = v;;
}

