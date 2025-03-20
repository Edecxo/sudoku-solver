#include <stdio.h>
#include <string.h>

#include "sudoku.h"
#include "verifier.h"

void main() {
  printf("Initializing...\n");
  sudoku_t *sudoku = blank_sudoku_new();
  sudoku_t *sudoku_valid = blank_sudoku_new();
  char input_valid_string[82] = "123456789456789123789123456231564897564897231897231564312645978645978312978312645";
  char input_invalid_string[82];
  strcpy(input_invalid_string, input_valid_string);
  for (int i = 0; i < 81; i++) {
    if (i % 5 == 0) input_invalid_string[i] = '?';
  }

  printf("Valid input string: %s\n", input_valid_string);
  printf("Invalid input string: %s\n", input_invalid_string);

  printf("Populating puzzles...\n");
  sudoku_populate(sudoku, input_invalid_string);
  sudoku_populate(sudoku_valid, input_valid_string);

  printf("Printing rows...\n");
  sudoku_print(sudoku);

  printf("Syncing...\n");
  sudoku_sync(sudoku_valid);
  sudoku_sync(sudoku);

  printf("Printing columns...\n");
  sudoku_print_columns(sudoku);

  printf("Printing boxes...\n");
  sudoku_print_boxes(sudoku);

  printf("Testing allocation...\n");
  sudoku_test_allocation(sudoku);

  printf("Verifying valid rows...\n");
  for (int i = 0; i < 9; i++) {
    printf("Row %d: %s\n", i + 1, (is_row_valid(sudoku_valid, i)) ? "Valid" : "Invalid");
  }

  printf("Verifying valid columns...\n");
  for (int i = 0; i < 9; i++) {
    printf("Column %d: %s\n", i + 1, (is_column_valid(sudoku_valid, i)) ? "Valid" : "Invalid");
  }

  printf("Verifying valid boxes...\n");
  for (int i = 0; i < 9; i++) {
    printf("Box %d: %s\n", i + 1, (is_box_valid(sudoku_valid, i)) ? "Valid" : "Invalid");
  }

  printf("Verifying valid solution...");
  if (is_sudoku_valid(sudoku_valid)) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  printf("Verifying invalid solution...");
  if (is_sudoku_valid(sudoku)) {
    printf("Valid\n");
  } else {
    printf("Invalid\n");
  }

  printf("Freeing...\n");
  sudoku_free(sudoku);
}

