#pragma once

#include "sudoku.h"

int is_row_valid(sudoku_t *sudoku, int row_idx);
int is_column_valid(sudoku_t *sudoku, int column_idx);
int is_box_valid(sudoku_t *sudoku, int box_idx);
int is_sudoku_valid(sudoku_t *sudoku);

char *possible_numbers(sudoku_t *sudoku, int row, int column);

void fill_in_cell(sudoku_t *sudoku, int row, int column, char value);

