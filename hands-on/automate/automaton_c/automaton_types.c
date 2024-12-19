/* --- Generated the 18/12/2024 at 23:55 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c automaton.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "automaton_types.h"

Automaton__alpha Automaton__alpha_of_string(char* s) {
  if ((strcmp(s, "A")==0)) {
    return Automaton__A;
  };
  if ((strcmp(s, "B")==0)) {
    return Automaton__B;
  };
  if ((strcmp(s, "C")==0)) {
    return Automaton__C;
  };
}

char* string_of_Automaton__alpha(Automaton__alpha x, char* buf) {
  switch (x) {
    case Automaton__A:
      strcpy(buf, "A");
      break;
    case Automaton__B:
      strcpy(buf, "B");
      break;
    case Automaton__C:
      strcpy(buf, "C");
      break;
    default:
      break;
  };
  return buf;
}

Automaton__astate Automaton__astate_of_string(char* s) {
  if ((strcmp(s, "X")==0)) {
    return Automaton__X;
  };
  if ((strcmp(s, "Y")==0)) {
    return Automaton__Y;
  };
  if ((strcmp(s, "Z")==0)) {
    return Automaton__Z;
  };
  if ((strcmp(s, "Dead")==0)) {
    return Automaton__Dead;
  };
}

char* string_of_Automaton__astate(Automaton__astate x, char* buf) {
  switch (x) {
    case Automaton__X:
      strcpy(buf, "X");
      break;
    case Automaton__Y:
      strcpy(buf, "Y");
      break;
    case Automaton__Z:
      strcpy(buf, "Z");
      break;
    case Automaton__Dead:
      strcpy(buf, "Dead");
      break;
    default:
      break;
  };
  return buf;
}

