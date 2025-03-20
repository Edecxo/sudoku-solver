#include "verifier.h"
#include "sudoku.h"
#include <stdio.h>

int is_row_valid(sudoku_t *sudoku, int row_idx) {
  int matches = 0;
  for (int num = 1; num < 10; num++) {
    for (int i = 0; i < 9; i++) {
      if (sudoku->rows[row_idx].row[i] == (num + '0')) {
        matches++;
      }
    }
  }
  return (matches == 9);
}

int is_column_valid(sudoku_t *sudoku, int column_idx) {
  int matches = 0;
  for (int num = 1; num < 10; num++) {
    for (int i = 0; i < 9; i++) {
      if (sudoku->columns[column_idx].column[i] == (num + '0')) {
        matches++;
      }
    }
  }
  return (matches == 9);
}

int is_box_valid(sudoku_t *sudoku, int box_idx) {
  int matches = 0;
  for (int num = 1; num < 10; num++) {
    for (int i = 0; i < 9; i++) {
      if (sudoku->boxes[box_idx].box[i] == (num + '0')) {
        matches++;
      }
    }
  }
  return (matches == 9);
}

int is_sudoku_valid(sudoku_t *sudoku) {
  int matches = 0;
  for (int i = 0; i < 9; i++) {
    if (is_row_valid(sudoku, i) &&
        is_column_valid(sudoku, i) &&
        is_box_valid(sudoku, i)
       ) {
      matches++;
    }
  }
  return (matches == 9);
}

