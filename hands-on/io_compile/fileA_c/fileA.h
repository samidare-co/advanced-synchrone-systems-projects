/* --- Generated the 2/11/2024 at 11:2 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c fileA.ept --- */

#ifndef FILEA_H
#define FILEA_H

#include "fileA_types.h"
#include "fileB.h"
typedef struct FileA__foo_out {
  int o;
} FileA__foo_out;

void FileA__foo_step(int i, FileA__foo_out* _out);

typedef struct FileA__bar_out {
  int o;
} FileA__bar_out;

void FileA__bar_step(int i, FileA__bar_out* _out);

#endif // FILEA_H
