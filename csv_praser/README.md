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
