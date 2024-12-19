/* --- Generated the 18/12/2024 at 21:23 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c min_list.ept --- */

#ifndef MIN_LIST_H
#define MIN_LIST_H

#include "min_list_types.h"
typedef struct Min_list__min_flot_mem {
  int v_3;
  int v;
} Min_list__min_flot_mem;

typedef struct Min_list__min_flot_out {
  int y;
} Min_list__min_flot_out;

void Min_list__min_flot_reset(Min_list__min_flot_mem* self);

void Min_list__min_flot_step(int x, Min_list__min_flot_out* _out,
                             Min_list__min_flot_mem* self);

#endif // MIN_LIST_H
