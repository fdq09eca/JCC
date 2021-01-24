# CSV parser

## spec

1. character `,` is allowed in the cell.
2. empty string is allowed in the cell.
3. there could be different column.
4. allocated memory must be released.

## plan

- [ ] read `*.csv` to the memory.
- [ ] create `struct cell`, `struct row`, `struct csv`.
- [ ] dump the `struct csv` to concole.

### read `*,csv`

- why do we prefer `void init_csv(CSV *csv, char *fn);` over `CSV init_csv(char *fn);`?

### create `struct row`

### create `struct cell`

## ref

[簡單黎講C Plus Plus](https://www.youtube.com/watch?v=cdTnj6rtEMI)
