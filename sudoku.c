#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "sudoku.h"

sudoku_t *blank_sudoku_new() {
  
  // Initializion of main sudoku_t and NULL checks
  // TODO: make columns and boxes
  sudoku_t *sudoku = malloc(sizeof(sudoku_t));
  if (sudoku == NULL) return;
  sudoku->rows = malloc(sizeof(row_t) * 9);
  if (sudoku->rows == NULL) {
    free(sudoku);
    return;
  }

  // Allocate memory for sudoku structs. Initialize with char '?'
  // TODO: columns and boxes here too
  // Note: No need to reinitialize the cells. Just define columns and boxes off rows
  for (int i = 0; i < 9; i++) {
    sudoku->rows[i].row = malloc(sizeof(char) * 9);
    if (sudoku->rows[i].row == NULL) return;
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      sudoku->rows[i].row[j] = '?';
    }
  }

  return sudoku;
}

void sudoku_print(sudoku_t *sudoku) {
  // Prints an ascii sudoku board. Will be filled with '?' if not populated
  // cat ./sudoku_print_example for reference

  printf("/-------+-------+-------\\\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j += 3) {
    // Print each row
    printf("| %c %c %c ",
        sudoku->rows[i].row[j], sudoku->rows[i].row[j+1], sudoku->rows[i].row[j+2]);
    }
    printf("|\n");
    // Print break after every third row. Hardcoded because there's only two
    if (i == 2 || i == 5) {
      printf("|-------+-------+-------|\n");
    }
  }
  printf("\\-------+-------+-------/\n");
}

void sudoku_free(sudoku_t *sudoku) {
  // Frees the given sudoku struct
  free(sudoku->rows);
  free(sudoku);
}
