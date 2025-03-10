#include <stdlib.h>
#include <stdio.h>

#include "sudoku.h"

sudoku_t *blank_sudoku_new() {
  sudoku_t *sudoku = malloc(sizeof(sudoku_t));
  if (sudoku == NULL) return;

  for (int i = 0; i < 9; i++) {
    row_t *new_row = malloc(sizeof(row_t));
    if (new_row == NULL) return;
    sudoku->rows[i] = *new_row;
    
    column_t *new_column = malloc(sizeof(column_t));
    if (new_column == NULL) return;
    sudoku->columns[i] = *new_column;
    /*
    box_t *new_box = malloc(sizeof(box_t));
    if (new_box == NULL) return;
    sudoku->boxes.box[i] = new_box;
    */

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      sudoku->rows[i].row[j] = "?";
    }
  }

  return sudoku;
  }
}

void sudoku_print(sudoku_t *sudoku) {
  printf("/-------+-------+-------\\\n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j += 3) {
    printf("| %c %c %c ",
        sudoku->rows[i].row[j], sudoku->rows[i].row[j+1], sudoku->rows[i].row[j+2]);
    }
    printf("|\n");
  }
  printf("\\-------+-------+-------/\n");
}

