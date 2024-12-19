/* --- Generated the 19/12/2024 at 1:53 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c alarme.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alarme.h"

void Alarme__alarme_reset(Alarme__alarme_mem* self) {
  self->cpt = 0;
}

void Alarme__alarme_step(int x, Alarme__alarme_out* _out,
                         Alarme__alarme_mem* self) {
  
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  int not_in;
  int not_in_2;
  v_7 = (self->cpt>2);
  v_5 = (self->cpt+1);
  v_4 = (x>35);
  v_3 = (x<0);
  not_in_2 = (v_3||v_4);
  v_8 = (v_7&&not_in_2);
  if (v_8) {
    _out->alarme = true;
  } else {
    _out->alarme = false;
  };
  v_1 = (x<0);
  v = (x>2);
  v_2 = (v||v_1);
  if (v_2) {
    not_in = true;
  } else {
    not_in = false;
  };
  if (not_in) {
    v_6 = v_5;
  } else {
    v_6 = 0;
  };
  self->cpt = v_6;;
}

