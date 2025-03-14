typedef struct Row {
  char *row;
} row_t;

typedef struct Column {
  char *column;
} column_t;

typedef struct Coordinates {
  short x;
  short y;
} coords_t;

typedef struct Box {
  coords_t coords;
  char *box;
} box_t;

typedef struct Sudoku {
  row_t *rows;
  column_t *columns;
  box_t *boxes;
} sudoku_t;

sudoku_t *blank_sudoku_new();
void sudoku_print(sudoku_t *sudoku);
void sudoku_free(sudoku_t *sudoku);
