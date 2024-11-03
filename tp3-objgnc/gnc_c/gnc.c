/* --- Generated the 1/11/2024 at 11:43 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c gnc.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gnc.h"

void Gnc__gnc_reset(Gnc__gnc_mem* self) {
  self->cnt = 0;
}

void Gnc__gnc_step(int i, Gnc__gnc_out* _out, Gnc__gnc_mem* self) {
  Extern__print_gnc_out Extern__print_gnc_out_st;
  
  int v;
  _out->o = (i-self->cnt);
  Extern__print_gnc_step(self->cnt, i, _out->o, &Extern__print_gnc_out_st);
  v = (self->cnt+1);
  self->cnt = v;;
}

void Gnc__fast_reset(Gnc__fast_mem* self) {
  self->cnt = 0;
}

void Gnc__fast_step(int i, Gnc__fast_out* _out, Gnc__fast_mem* self) {
  Extern__print_fast_out Extern__print_fast_out_st;
  
  int v_1;
  int v;
  v_1 = (2*i);
  _out->o = (v_1+self->cnt);
  Extern__print_fast_step(self->cnt, i, _out->o, &Extern__print_fast_out_st);
  v = (self->cnt+1);
  self->cnt = v;;
}

void Gnc__thermal_reset(Gnc__thermal_mem* self) {
  self->cnt = 0;
}

void Gnc__thermal_step(Gnc__thermal_out* _out, Gnc__thermal_mem* self) {
  Extern__print_thermal_out Extern__print_thermal_out_st;
  
  int v;
  Extern__print_thermal_step(self->cnt, &Extern__print_thermal_out_st);
  v = (self->cnt+1);
  self->cnt = v;;
}

void Gnc__condact_gnc_params_99__reset(Gnc__condact_gnc_params_99__mem* self) {
  Gnc__gnc_reset(&self->gnc);
  self->w = 99;
}

void Gnc__condact_gnc_params_99__step(int c, int y,
                                      Gnc__condact_gnc_params_99__out* _out,
                                      Gnc__condact_gnc_params_99__mem* self) {
  Gnc__gnc_out Gnc__gnc_out_st;
  
  int q;
  if (c) {
    Gnc__gnc_step(y, &Gnc__gnc_out_st, &self->gnc);
    q = Gnc__gnc_out_st.o;
    _out->x = q;
  } else {
    _out->x = self->w;
  };
  self->w = _out->x;;
}

void Gnc__condact_f_params_31__reset(Gnc__condact_f_params_31__mem* self) {
  Gnc__fast_reset(&self->fast);
  self->v_2 = 31;
}

void Gnc__condact_f_params_31__step(int c, int y,
                                    Gnc__condact_f_params_31__out* _out,
                                    Gnc__condact_f_params_31__mem* self) {
  Gnc__fast_out Gnc__fast_out_st;
  
  int v;
  if (c) {
    Gnc__fast_step(y, &Gnc__fast_out_st, &self->fast);
    v = Gnc__fast_out_st.o;
    _out->x = v;
  } else {
    _out->x = self->v_2;
  };
  self->v_2 = _out->x;;
}

void Gnc__call_thermal_reset(Gnc__call_thermal_mem* self) {
  Gnc__thermal_reset(&self->thermal);
}

void Gnc__call_thermal_step(int c, Gnc__call_thermal_out* _out,
                            Gnc__call_thermal_mem* self) {
  Gnc__thermal_out Gnc__thermal_out_st;
  Gnc__thermal_step(&Gnc__thermal_out_st, &self->thermal);
}

void Gnc__condact_thermal_reset(Gnc__condact_thermal_mem* self) {
  Gnc__call_thermal_reset(&self->call_thermal);
}

void Gnc__condact_thermal_step(int c, Gnc__condact_thermal_out* _out,
                               Gnc__condact_thermal_mem* self) {
  Gnc__call_thermal_out Gnc__call_thermal_out_st;
  if (c) {
    Gnc__call_thermal_step(true, &Gnc__call_thermal_out_st,
                           &self->call_thermal);
  };
}

void Gnc__main_reset(Gnc__main_mem* self) {
  Gnc__condact_f_params_31__reset(&self->condact_f);
  Gnc__condact_gnc_params_99__reset(&self->condact_gnc);
  Gnc__condact_thermal_reset(&self->condact_thermal);
  self->v_4 = 99;
  self->mif_cnt = 0;
}

void Gnc__main_step(Gnc__main_out* _out, Gnc__main_mem* self) {
  Gnc__condact_f_params_31__out Gnc__condact_f_params_31__out_st;
  Gnc__condact_gnc_params_99__out Gnc__condact_gnc_params_99__out_st;
  Gnc__condact_thermal_out Gnc__condact_thermal_out_st;
  
  int v_3;
  int v;
  int x;
  int y;
  int clk_f;
  int clk_gnc;
  int clk_thermal;
  clk_gnc = (self->mif_cnt==9);
  clk_thermal = (self->mif_cnt==0);
  clk_f = true;
  Gnc__condact_f_params_31__step(clk_f, self->v_4,
                                 &Gnc__condact_f_params_31__out_st,
                                 &self->condact_f);
  y = Gnc__condact_f_params_31__out_st.x;
  Gnc__condact_gnc_params_99__step(clk_gnc, y,
                                   &Gnc__condact_gnc_params_99__out_st,
                                   &self->condact_gnc);
  x = Gnc__condact_gnc_params_99__out_st.x;
  v = (self->mif_cnt+1);
  v_3 = (v%10);
  if (clk_thermal) {
    Gnc__condact_thermal_step(true, &Gnc__condact_thermal_out_st,
                              &self->condact_thermal);
  };
  self->v_4 = x;
  self->mif_cnt = v_3;;
}

