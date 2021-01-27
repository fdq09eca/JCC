# CSV parser

## quick start

```sh
make main && ./main
```

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

## note

1. Marco `debug_print`:

```c
#if _DEBUG
  #define debug_print(...)  printf(__VA_ARGS__)
#else
  #define debug_print(...)
#endif
```

2. debug time.
3. `cell->data = strdup(buff)`
   1. one working buffer -> `strdup(buff)` for the result to reduce memory footprint.
4. double quote feature can't handle single double quote.
   1. "Samsung U600 24""asas" -> Samsung U600 24"

## note 2

- dangling pointer
- ownership concept
- PAIRING
  - init -> release
  - open -> close
  - size -> array
  - allocate -> free, even pointer, consider ownship
  - check buffer size to prevent buffer overrun.

## HW

- printf

```c
void my_printf(const char* fmt, int p0, char* p2) {
}


int a = 10;
char* s = "Hello";

my_printf("a=[%04d] s=[%10s]", a, s);

a=[0010] s=[     Hello]
```

- link list
  - insert
  - del(idx)
  - reverse
- double link list
- dynamic array
  - insert(idx)

- black jack.

number of Deck?

number of Player (Max 8)? 3

Player1 $: inital $ -> 100
Player2 $: inital $ -> 100
Player3 $: inital $ -> 100

$: 0
Bet: 10

Dealer: 9s
Player: Qh, As

`BJ? bet * 1.5 : bet;`

Player: more card? [Y/N]

<!-- Player: split [Y/N] -->
<!-- Player: double bet [Y/N] -->
<!-- Player:  -->

