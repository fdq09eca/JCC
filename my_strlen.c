#include <stdio.h>

int my_strlen(char *s)
{
    int c = 0;
    while (*(s++))
    {
        c++;
    }
    return c;
}

int main(void)
{
    const char str[] = "How many characters does this string contain?";
    printf("without null character: %zu\n", my_strlen(str));
    printf("with null character:    %zu\n", sizeof str);
}