#include <stdio.h>
#include <stdlib.h>

int n_row(char *filename);
int n_col(char *filename);
void print_csv(char **csv, int R, int C);

int main(int argc, char **argv)
{
    char *filename = argv[1];
    // FILE *f = fopen("test.csv", "r");
    FILE *f = fopen(filename, "r");
    char ch;
    int R = n_row(filename);
    int C = n_col(filename);
    char *csv[R][C];
    char *buff;

    int r = 0, c = 0;
    int i = 0;

    while ((ch = fgetc(f)) != EOF)
    {
        if (i == 0)
        {
            buff = (char *)malloc(sizeof(char) * 100);
        }
        if (ch == ',')
        {
            buff[i] = '\0';
            i = 0;
            csv[r][c] = buff;
            // printf("r = %i; c = %i\n", r, c);
            c++;
        }
        else if (ch == '\n')
        {
            buff[i] = '\0';
            i = 0;
            csv[r][c] = buff;
            // printf("r = %i; c = %i\n", r, c);
            r++;
            c = 0;
        }
        else
        {
            if (ch == ' ' && i == 0)
            {
                continue;
            }
            buff[i] = ch;
            i++;
        }
    }
    fclose(f);

    // print_csv(csv, R, C);

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

    return 0;
}

int n_row(char *filename)
{
    FILE *f = fopen(filename, "r");
    char ch;
    int r = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
        {
            r++;
        }
    }
    fclose(f);
    // printf("total row: %i\n", r);
    return r;
}

int n_col(char *filename)
{
    FILE *f = fopen(filename, "r");
    char ch;
    int c = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == ',')
        {
            c++;
        }
    }
    fclose(f);
    c = c / n_row(filename) + 1;
    // printf("total col: %i\n", c);
    return c;
}

// void print_csv(char **csv, int R, int C)
// {
//     for (int i = 0; i < R; i++)
//     {
//         for (int j = 0; j < C; j++)
//         {
//             // printf("<%i><%i> %s\n", i, j, csv[i][j]);
//             printf("%s ", csv[i][j]);
//             if (j == C - 1)
//             {
//                 printf("\n");
//             }
//         }
//     }
// }