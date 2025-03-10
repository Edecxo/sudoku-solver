#include "sudoku.c"
#include <stdio.h>

void main() {
  sudoku_t *sudoku = blank_sudoku_new();
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      sudoku->rows[i].row[j] = "?";
    }
  }
  sudoku_print(sudoku);
}

