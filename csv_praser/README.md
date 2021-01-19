# CSV praser

## Quick start

```bash
./main test.csv   
```

## Objective

- Read the csv file and print it to console.

## Assumption

1. `csv` file has no `,` in elements.
2. `csv` file row must end by a `\n` i.e. newline character.
3. `csv` file must be balance. i.e. no missing delimitor (`,`)

## Question

1. How to use `fread`/`fwrite` for byte by byte file reading/writing?
2. How to put the following in to a function and call it in the main?

```c
for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%s ", csv[i][j]);
            if (j == C - 1)
            {
                printf("\n");
            }
        }
    }
```

It is what I tried:

```c
void print_csv(char **csv, int R, int C)
for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // printf("<%i><%i> %s\n", i, j, csv[i][j]);
            printf("%s ", csv[i][j]);
            if (j == C - 1)
            {
                printf("\n");
            }
        }
    }
```

and i call it like this

```c
print_csv(csv, R, C);
```

where `csv` is a 2d `char` pointer array.

Here is the error

```sh
~/JCC/csv_praser(master*) » make main &&./main test.csv                                                                                                                            macone@Macs-MBP
cc     main.c   -o main
main.c:57:15: warning: incompatible pointer types passing 'char *[R][C]' to parameter of type 'char **' [-Wincompatible-pointer-types]
    print_csv(csv, R, C);
              ^~~
main.c:6:23: note: passing argument to parameter 'csv' here
void print_csv(char **csv, int R, int C);
                      ^
main.c:117:27: warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
            printf("%s ", csv[i][j]);
                    ~~    ^~~~~~~~~
                    %c
2 warnings generated.
[1]    25830 segmentation fault  ./main test.csv
```