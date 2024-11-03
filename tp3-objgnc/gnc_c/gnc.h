/* --- Generated the 1/11/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c gnc.ept --- */

#ifndef GNC_H
#define GNC_H

#include "gnc_types.h"
#include "extern.h"
typedef struct Gnc__gnc_mem {
  int cnt;
} Gnc__gnc_mem;

typedef struct Gnc__gnc_out {
  int o;
} Gnc__gnc_out;

void Gnc__gnc_reset(Gnc__gnc_mem* self);

void Gnc__gnc_step(int i, Gnc__gnc_out* _out, Gnc__gnc_mem* self);

typedef struct Gnc__fast_mem {
  int cnt;
} Gnc__fast_mem;

typedef struct Gnc__fast_out {
  int o;
} Gnc__fast_out;

void Gnc__fast_reset(Gnc__fast_mem* self);

void Gnc__fast_step(int i, Gnc__fast_out* _out, Gnc__fast_mem* self);

typedef struct Gnc__thermal_mem {
  int cnt;
} Gnc__thermal_mem;

typedef struct Gnc__thermal_out {
} Gnc__thermal_out;

void Gnc__thermal_reset(Gnc__thermal_mem* self);

void Gnc__thermal_step(Gnc__thermal_out* _out, Gnc__thermal_mem* self);

typedef struct Gnc__condact_gnc_params_99__mem {
  int w;
  Gnc__gnc_mem gnc;
} Gnc__condact_gnc_params_99__mem;

typedef struct Gnc__condact_gnc_params_99__out {
  int x;
} Gnc__condact_gnc_params_99__out;

void Gnc__condact_gnc_params_99__reset(Gnc__condact_gnc_params_99__mem* self);

void Gnc__condact_gnc_params_99__step(int c, int y,
                                      Gnc__condact_gnc_params_99__out* _out,
                                      Gnc__condact_gnc_params_99__mem* self);

typedef struct Gnc__condact_f_params_31__mem {
  int v_2;
  Gnc__fast_mem fast;
} Gnc__condact_f_params_31__mem;

typedef struct Gnc__condact_f_params_31__out {
  int x;
} Gnc__condact_f_params_31__out;

void Gnc__condact_f_params_31__reset(Gnc__condact_f_params_31__mem* self);

void Gnc__condact_f_params_31__step(int c, int y,
                                    Gnc__condact_f_params_31__out* _out,
                                    Gnc__condact_f_params_31__mem* self);

typedef struct Gnc__call_thermal_mem {
  Gnc__thermal_mem thermal;
} Gnc__call_thermal_mem;

typedef struct Gnc__call_thermal_out {
} Gnc__call_thermal_out;

void Gnc__call_thermal_reset(Gnc__call_thermal_mem* self);

void Gnc__call_thermal_step(int c, Gnc__call_thermal_out* _out,
                            Gnc__call_thermal_mem* self);

typedef struct Gnc__condact_thermal_mem {
  Gnc__call_thermal_mem call_thermal;
} Gnc__condact_thermal_mem;

typedef struct Gnc__condact_thermal_out {
} Gnc__condact_thermal_out;

void Gnc__condact_thermal_reset(Gnc__condact_thermal_mem* self);

void Gnc__condact_thermal_step(int c, Gnc__condact_thermal_out* _out,
                               Gnc__condact_thermal_mem* self);

typedef struct Gnc__main_mem {
  int v_4;
  int mif_cnt;
  Gnc__condact_thermal_mem condact_thermal;
  Gnc__condact_gnc_params_99__mem condact_gnc;
  Gnc__condact_f_params_31__mem condact_f;
} Gnc__main_mem;

typedef struct Gnc__main_out {
} Gnc__main_out;

void Gnc__main_reset(Gnc__main_mem* self);

void Gnc__main_step(Gnc__main_out* _out, Gnc__main_mem* self);

#endif // GNC_H
