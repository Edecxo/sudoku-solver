typedef struct Row {
  char row[9];
} row_t;

typedef struct Column {
  char column[9];
} column_t;

typedef struct Coordinates {
  short x;
  short y;
} coords_t;

typedef struct Box {
  coords_t coords;
  char box[9];
} box_t;

typedef struct Sudoku {
  row_t rows[9];
  column_t columns[9];
  box_t boxes[9];
} sudoku_t;

sudoku_t *blank_sudoku_new();
void sudoku_print(sudoku_t *sudoku);
void sudoku_free(sudoku_t *sudoku);
