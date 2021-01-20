#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char *str1);

int main(void)
{
    char *s1 = "Duplicate me!";
    char *s2 = my_strdup(s1);
    printf("s2 = \"%s\"\n", s2);
    free(s2);
}

char *my_strdup(char *str1)
{
    int c = 0;
    char *s = str1;
    for (; *s; s++, c++)
        ;
    char *dup_s = (char *)malloc(c * sizeof(char));
    char *d = dup_s;
    while ((*dup_s++ = *str1++))
        ;
    // while (*str1)
    // {
    //     *dup_s = *str1;
    //     str1++;
    //     dup_s++;
    // };
    return d;
}