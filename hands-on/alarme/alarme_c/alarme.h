/* --- Generated the 19/12/2024 at 0:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c alarme.ept --- */

#ifndef ALARME_H
#define ALARME_H

#include "alarme_types.h"
typedef struct Alarme__alarme_out {
  int alarme;
} Alarme__alarme_out;

void Alarme__alarme_step(int x, Alarme__alarme_out* _out);

#endif // ALARME_H