#include <stdio.h>
char *my_strcat(char *dest, const char *src);

int main()
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    my_strcat(str, str2);
    my_strcat(str, " ...");
    my_strcat(str, " Goodbye World!");
    puts(str);
    return 0;
}

char *my_strcat(char *dest, const char *src)
{
    char *rtn = dest;
    while (*src)
    {
        if (*dest)
        {
            dest++;
        }
        else
        {
            *dest = *src;
            src++;
        }
    }
    dest = 0;

    return rtn;
}