#include <stdio.h>

#include "sudoku.h"

void main() {
  printf("Initializing...\n");
  sudoku_t *sudoku = blank_sudoku_new();
  char input_string[82] = "123456789456789123789123456231564897564897231897231564312645978645978312978312645";
  for (int i = 0; i < 81; i++) {
    if (i % 5 == 0) input_string[i] = '?';
  }

  printf("Input string: %s\n", input_string);

  printf("Populating...\n");
  sudoku_populate(sudoku, input_string);

  printf("Printing...\n");
  sudoku_print(sudoku);

  printf("Testing allocation...\n");
  sudoku_test_allocation(sudoku);

  printf("Freeing...\n");
  sudoku_free(sudoku);
}

