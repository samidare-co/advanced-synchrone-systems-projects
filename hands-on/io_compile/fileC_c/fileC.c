/* --- Generated the 2/11/2024 at 11:3 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c fileC.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileC.h"

void FileC__foo_step(int i, FileC__foo_out* _out) {
  FileB__print_io_out FileB__print_io_out_st;
  _out->o = (i*2);
  FileB__print_io_step(i, _out->o, &FileB__print_io_out_st);
}

