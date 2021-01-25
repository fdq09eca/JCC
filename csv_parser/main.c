#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    size_t cell_n;
} CELL;

typedef struct
{
    char *data;
    size_t n_cell;
    size_t row_n;
    CELL *cells;
} ROW;

typedef struct
{
    char *name;
    char *data;
    size_t n_row;
    ROW *rows;
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
void print_rows(CSV *csv);
void print_csv(CSV *csv);

int main()
{
    CSV csv;
    init_csv(&csv, "test.csv");
    // print_csv(&csv);
    close_csv(&csv);
    return 0;
}

size_t n_cell(ROW *row)
{
    size_t n = 0;
    for (char *c = row->data; *c; c++)
    {
        if (*c == ',')
        {
            n++;
        }
    }
    return n + 1;
}

char *parse_cell(ROW *row, char** save)
{
    // static char *save = NULL;
    char *buff = malloc(200 * sizeof(char));

    char *b = buff;
    char *c = *save ? *save : row->data;
    
    for (; *c; c++, b++)
    {
        *b = *c;
        if (*c == ',')
        {
            *b = 0;
            *save = c + 1;
            return buff;
        }
    }
    return NULL;
}

void load_cell(ROW *row)
{
    size_t row_n = row->row_n;
    CELL *cell = row->cells;
    CELL *end = cell + row->n_cell;
    char * save = NULL;
    for (int n = 0; cell < end; cell++, n++)
    {
        char* c = parse_cell(row, &save);
        if (!c)
        {
            break;
        }
        printf("load cell%zu%i: %s\n", row_n, n, c);
        cell->cell_n = n;
        cell->data = c;
    }
    return;
}

size_t n_row(CSV *csv)
{
    size_t n = 0;
    for (char *c = csv->data; *c; c++)
    {
        if (*c == '\n')
        {
            n++;
        }
    }
    return n;
}

void init_row(ROW *row, size_t n, char *data)
{
    row->data = data;
    row->row_n = n;
    row->n_cell = n_cell(row);
    row->cells = (CELL *)malloc(sizeof(CELL) * row->n_cell);
    load_cell(row);
    return;
}

char *parse_row(CSV *csv)
{
    static char *save = NULL;
    char *buff = malloc(200 * sizeof(char));

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

void load_rows(CSV *csv)
{
    ROW *row = csv->rows;
    ROW *end = row + csv->n_row;
    for (int n = 0; row < end; row++, n++)
    {
        char *data = parse_row(csv);
        if (!data)
            return;
        printf("load row %i...\n", n);
        init_row(row, n, data);
    }
    return;
}

void print_rows(CSV *csv)
{
    ROW *row = csv->rows;
    ROW *end = row + csv->n_row;

    for (; row < end; row++)
    {
        puts(row->data);
    }
    return;
}

void print_csv(CSV *csv)
{
    printf("name: %s\ndata: %p\nn_row: %zu\nrows %p\n", csv->name, csv->data, csv->n_row, csv->rows);
    print_rows(csv);
    return;
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
    csv->n_row = n_row(csv);
    csv->rows = (ROW *)malloc(sizeof(ROW) * csv->n_row);
    load_rows(csv);
    // csv->rows = ROW arr[csv->n_row];
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

void free_cells(ROW* row) {
    CELL *cell = row->cells;
    CELL *end = cell + row->n_cell;
    size_t row_n = row->row_n;

    for (int cell_n = 0; cell < end; cell++, cell_n++) {
        printf("cell: %zu%i freed.\n", row_n, cell_n);
        free(cell->data);
    }
    free(row->cells);
    printf("all cells in row %zu freed.\n", row->row_n);
}

void free_rows(CSV *csv)
{
    ROW *row = csv->rows;
    ROW *end = row + csv->n_row;

    for (int roll_n = 0; row < end; row++, roll_n++)
    {
        free_cells(row);
        printf("row %i freed.\n", roll_n);
        free(row->data);

    }
    free(csv->rows);
    printf("all rows freed.\n");
}

void close_csv(CSV *csv)
{
    free(csv->data);
    free_rows(csv);
    puts("csv closed.\n");
    return;
}

char* trim(char* str) {
    char*s = str;

    for (char* s = str; *s; s++) {
        if (*s != ' ') {
            break;
        }
    }
    return s;
}

char* nextchr(char* str, char ch) {
    int c = 0;
    for (char* s = str; *s ; s++ ) {
        if (*s == ch) {
            c++;
        }
        if (c == 2) {
            return s;
        }
    }
    return str;
}