#pragma once

bool is_row_valid(sudoku_t *sudoku);
bool is_column_valid(sudoku_t *sudoku);
bool is_box_valid(sudoku_t *sudoku);
bool is_sudoku_valid(sudoku_t *sudoku);

char *possible_numbers(sudoku_t sudoku, int row, int column);

void fill_in_cell(sudoku_t sudoku, int row, int column, char value);
