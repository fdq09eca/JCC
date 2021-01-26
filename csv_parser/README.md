# CSV parser

## spec

- [x] character `,`, `\n` is allowed in the cell.
- [x] empty string is allowed in the cell.
- [x] there could be different column.
- [x] all allocated memory must be released.

## logic flow

1. read `.csv`
2. get `.csv` size -> `size_t fs`.
3. `melloc(fs * sizeof(char))` -> get `char* csv.data`
4. `fread` once to `csv.data` with `fs` from `.csv` stream.
5. count number of row (`n_row`) in the `.csv`
6. `(ROW*) melloc(n_row * sizeof(ROW))` -> get `ROW* csv.rows`
7. @`row`
   1. assign `ROW*` from `csv.rows`
   2. parse `row` -> get `row.data`
   3. count number of cell (`n_cell`) in the `row`
   4. `(CELL*) melloc(n_cell * sizeof(CELL))` -> get `CELL* row.cells`
   5. @cell
      1. assign `CELL*` from `row.cells`
      2. parse `cell` -> get `cell.data`
8. free all allocate memory
   1. `free` `rows`@`csv`
   2. `free` `cells`@`row`

## ref

[簡單黎講C Plus Plus](https://www.youtube.com/watch?v=cdTnj6rtEMI)
