/* --- Generated the 2/11/2024 at 11:2 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. sep. 30 1:47:55 CET 2024) --- */
/* --- Command line: /Users/sami/.opam/default/bin/heptc -target c fileA.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileA.h"

void FileA__foo_step(int i, FileA__foo_out* _out) {
  FileB__print_io_out FileB__print_io_out_st;
  _out->o = i;
  FileB__print_io_step(i, _out->o, &FileB__print_io_out_st);
}

void FileA__bar_step(int i, FileA__bar_out* _out) {
  FileB__print_io_out FileB__print_io_out_st;
  
  int x;
  x = 42;
  _out->o = (i+x);
  FileB__print_io_step(i, _out->o, &FileB__print_io_out_st);;
}

