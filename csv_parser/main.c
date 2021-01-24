#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    char *content;
} CSV;

char *file_ext(const char *fn);
int my_strcmp(const char *str1, const char *str2);
int is_csv(const char *fn);
FILE *open_csv(const char *fn, char *);
size_t file_size(FILE *f);
char *read_csv(const char *fn);
void init_csv(CSV *csv, char *fn);
void close_csv(CSV *csv);


int main()
{
    CSV csv;
    init_csv(&csv, "test.csv");
    // char *csv_ptr = read_csv("test.csv");
    puts(csv.content);
    close_csv(&csv);
    return 0;
}

void init_csv(CSV *csv, char *fn)
{
    char *content = read_csv(fn);
    if (!content)
    {
        puts("NULL content.");
    }
    csv->name = fn;
    csv->content = content;
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

void close_csv(CSV* csv)
{
    free(csv->content);
    puts("csv closed.\n");
    return;
}