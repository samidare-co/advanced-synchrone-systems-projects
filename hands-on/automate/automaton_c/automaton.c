/* --- Generated the 18/12/2024 at 23:55 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c automaton.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "automaton.h"

void Automaton__automate_reset(Automaton__automate_mem* self) {
  self->v_24 = true;
  self->v_22 = true;
  self->v_20 = true;
  self->sprev = Automaton__X;
}

void Automaton__automate_step(Automaton__alpha l,
                              Automaton__automate_out* _out,
                              Automaton__automate_mem* self) {
  
  int v_33;
  int v_31;
  int v_29;
  int v_27;
  int v_26;
  int v_25;
  int v_23;
  int v_21;
  int v_19;
  Automaton__astate v_18;
  Automaton__astate v_17;
  Automaton__astate v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  Automaton__astate s;
  v_26 = (l==Automaton__B);
  v_25 = (l==Automaton__A);
  v_27 = (v_25||v_26);
  if (self->v_24) {
    v_29 = v_27;
  } else {
    v_29 = self->v_28;
  };
  v_23 = (l==Automaton__B);
  if (self->v_22) {
    v_31 = v_23;
  } else {
    v_31 = self->v_30;
  };
  v_21 = (l==Automaton__C);
  if (self->v_20) {
    v_33 = v_21;
  } else {
    v_33 = self->v_32;
  };
  v_14 = (self->sprev==Automaton__Z);
  v_12 = (l==Automaton__A);
  v_13 = (true&&v_12);
  v_15 = (v_13&&v_14);
  if (v_15) {
    v_16 = Automaton__Y;
  } else {
    v_16 = Automaton__Dead;
  };
  v_10 = (self->sprev==Automaton__Y);
  v_8 = (l==Automaton__C);
  v_9 = (true&&v_8);
  v_11 = (v_9&&v_10);
  if (v_11) {
    v_17 = Automaton__Z;
  } else {
    v_17 = v_16;
  };
  v_6 = (self->sprev==Automaton__Y);
  v_4 = (l==Automaton__B);
  v_5 = (true&&v_4);
  v_7 = (v_5&&v_6);
  if (v_7) {
    v_18 = Automaton__Y;
  } else {
    v_18 = v_17;
  };
  v_2 = (self->sprev==Automaton__X);
  v = (l==Automaton__A);
  v_1 = (true&&v);
  v_3 = (v_1&&v_2);
  if (v_3) {
    s = Automaton__Y;
  } else {
    s = v_18;
  };
  v_19 = (s==Automaton__Dead);
  if (v_19) {
    _out->accept = false;
  } else {
    _out->accept = v_33;
  };
  self->v_32 = v_31;
  self->v_30 = v_29;
  self->v_28 = false;
  self->v_24 = false;
  self->v_22 = false;
  self->v_20 = false;
  self->sprev = s;;
}

