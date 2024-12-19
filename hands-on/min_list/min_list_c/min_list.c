/* --- Generated the 18/12/2024 at 21:23 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c min_list.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "min_list.h"

void Min_list__min_flot_reset(Min_list__min_flot_mem* self) {
  self->v = true;
}

void Min_list__min_flot_step(int x, Min_list__min_flot_out* _out,
                             Min_list__min_flot_mem* self) {
  
  int v_2;
  int v_1;
  if (self->v) {
    _out->y = x;
  } else {
    _out->y = self->v_3;
  };
  v_1 = (x<_out->y);
  if (v_1) {
    v_2 = x;
  } else {
    v_2 = _out->y;
  };
  self->v_3 = v_2;
  self->v = false;;
}

