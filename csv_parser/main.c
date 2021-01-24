#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    int cell_n;
} CELL;

typedef struct
{
    char* data;
    int row_n;
    CELL* cells[];
} ROW;

typedef struct
{
    char *name;
    char *data;
    int n_row;
    int n_col;
    ROW* rows[];
} CSV;


char *file_ext(const char *fn);
int my_strcmp(const char *str1, const char *str2);
int is_csv(const char *fn);
FILE *open_csv(const char *fn, char *);
size_t file_size(FILE *f);
char *read_csv(const char *fn);
void init_csv(CSV *csv, char *fn);
void close_csv(CSV *csv);
char *parse_row(CSV *csv);

int main()
{
    CSV csv;
    init_csv(&csv, "test.csv");
    // char *csv_ptr = read_csv("test.csv");
    // puts(csv.data);

    for (int i = 0;; i++)
    {
        char *r = parse_row(&csv);
        if (!r)
        {
            break;
        }
        printf("row%i: %s\n", i, r);
    }

    // char* r; int i = 0;
    // while ((r = parse_row(&csv))){
    //     printf("row %d: %s\n", i, r);
    //     i++;
    // }
    // printf("%s\n", parse_row(&csv));
    // printf("%s\n", parse_row(&csv));
    close_csv(&csv);
    return 0;
}


char *parse_row(CSV *csv)
{
    static char *save = NULL;
    static char buff[200];
    char *b = buff;
    char *c = save ? save : csv->data;
    for (; *c; c++, b++)
    {
        *b = *c;
        if (*c == '\n')
        {
            *b = 0;
            save = c + 1;
            return buff;
        }
    }
    return NULL;
}
void init_row(ROW* row, char* data) {
    
}

void init_csv(CSV *csv, char *fn)
{
    char *data = read_csv(fn);
    if (!data)
    {
        puts("NULL data.");
    }
    csv->name = fn;
    csv->data = data;
    return;
}

char *read_csv(const char *fn)
{
    FILE *f = open_csv(fn, "r");
    if (!f)
    {
        puts("open csv failed.\n");
        return NULL;
    }
    size_t fs = file_size(f);
    char *fc = (char *)malloc(fs * sizeof(char));
    if (!fc)
    {
        puts("malloc failed.\n");
        return NULL;
    }
    fread(fc, fs, 1, f);
    fclose(f);
    return fc;
}

FILE *open_csv(const char *fn, char *mode)
{
    return (!is_csv(fn)) ? NULL : fopen(fn, mode);
}

size_t file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    return size;
}

int is_csv(const char *fn)
{
    return my_strcmp(file_ext(fn), ".csv") ? 0 : 1;
}

char *file_ext(const char *fn)
{
    for (; *fn; fn++)
    {
        if (*fn == '.')
            return (char *)fn;
    }
    return NULL;
}

int my_strcmp(const char *str1, const char *str2)
{
    for (; *str1; str1++, str2++)
    {
        if (*str1 != *str2)
            break;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void close_csv(CSV *csv)
{
    free(csv->data);
    puts("csv closed.\n");
    return;
}