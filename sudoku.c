#include <stdlib.h>
#include <stdio.h>
#include <math.h> //floor function

#include "sudoku.h"

sudoku_t *blank_sudoku_new() {
  
  // Initializion of main sudoku_t and NULL checks
  sudoku_t *sudoku = malloc(sizeof(sudoku_t));
  if (sudoku == NULL) return;
  sudoku->rows = malloc(sizeof(row_t) * 9);
  if (sudoku->rows == NULL) {
    sudoku_free(sudoku);
    return;
  }
  sudoku->columns = malloc(sizeof(column_t) * 9);
  if (sudoku->columns == NULL) {
    sudoku_free(sudoku);
    return;
  }
  sudoku->boxes = malloc(sizeof(box_t) * 9);
  if (sudoku->boxes == NULL) {
    sudoku_free(sudoku);
    return;
  }

  // Allocate memory for sudoku structs. Initialize with char '?'
  for (int i = 0; i < 9; i++) {
    sudoku->rows[i].row = malloc(sizeof(char) * 9);
    if (sudoku->rows[i].row == NULL) return;
    sudoku->columns[i].column = malloc(sizeof(char) * 9);
    if (sudoku->columns[i].column == NULL) return;
    sudoku->boxes[i].box= malloc(sizeof(char) * 9);
    if (sudoku->boxes[i].box== NULL) return;
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      sudoku->rows[i].row[j] = '?';
    }
  }
  sudoku_sync(sudoku);

  return sudoku;
}

int sudoku_test_allocation(sudoku_t *sudoku) {
  char t;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      t = sudoku->rows[i].row[j];
      //t = sudoku->columns[i].column[j];
      //t = sudoku->boxes[i].box[j];
    }
  }
  return 0;
}

void sudoku_sync(sudoku_t *sudoku) {
  for (int i = 0; i < 9; i++) {
    sudoku->boxes[i].coords.x = i % 3;
    sudoku->boxes[i].coords.y = floor(i / 3);
    for (int j = 0; j < 9; j++) {
      char value = sudoku->rows[i].row[j];
      sudoku->columns[i].column[j] = value;
    }
  }
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

void sudoku_populate(sudoku_t *sudoku, char *input) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int index = (i * 9) + j;
      sudoku->rows[i].row[j] = input[index];
    }
  }
}

void sudoku_free(sudoku_t *sudoku) {
  // Frees the given sudoku struct
  for (int i = 0; i < 9; i++) {
    if (sudoku->rows[i].row != NULL) free(sudoku->rows[i].row);
    if (sudoku->columns[i].column != NULL) free(sudoku->columns[i].column);
    if (sudoku->boxes[i].box != NULL) free(sudoku->boxes[i].box);
  }
  if (sudoku->rows != NULL) free(sudoku->rows);
  if (sudoku->columns != NULL) free(sudoku->columns);
  if (sudoku->boxes != NULL) free(sudoku->boxes);
  if (sudoku != NULL) free(sudoku);
}
