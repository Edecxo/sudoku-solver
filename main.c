#include <stdio.h>

#include "sudoku.h"

void main() {
  sudoku_t *sudoku = blank_sudoku_new();
  sudoku_print(sudoku);
  sudoku_free(sudoku);
}

