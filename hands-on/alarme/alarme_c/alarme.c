/* --- Generated the 19/12/2024 at 0:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c alarme.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alarme.h"

void Alarme__alarme_step(int x, Alarme__alarme_out* _out) {
  
  int v_1;
  int v;
  int not_in;
  v_1 = (x<-2);
  v = (x>2);
  not_in = (v||v_1);
  if (not_in) {
    _out->alarme = true;
  } else {
    _out->alarme = false;
  };;
}

