/* --- Generated the 10/12/2024 at 12:26 --- */
/* --- heptagon compiler, version 1.05.00 (compiled fri. sep. 27 23:48:47 CET 2024) --- */
/* --- Command line: /home/sami/.opam/default/bin/heptc -target c scheduler_data.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scheduler_data_types.h"

Scheduler_data__task_state Scheduler_data__task_state_of_string(char* s) {
  if ((strcmp(s, "Running")==0)) {
    return Scheduler_data__Running;
  };
  if ((strcmp(s, "Ready")==0)) {
    return Scheduler_data__Ready;
  };
  if ((strcmp(s, "Waiting")==0)) {
    return Scheduler_data__Waiting;
  };
}

char* string_of_Scheduler_data__task_state(Scheduler_data__task_state x,
                                           char* buf) {
  switch (x) {
    case Scheduler_data__Running:
      strcpy(buf, "Running");
      break;
    case Scheduler_data__Ready:
      strcpy(buf, "Ready");
      break;
    case Scheduler_data__Waiting:
      strcpy(buf, "Waiting");
      break;
    default:
      break;
  };
  return buf;
}

