#include <stdio.h>

char *my_strcpy(char *dest, char *src)
{
    char *ret = dest;
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *(dest) = 0;

    return ret;
}

int main()
{
    char arr[10];
    my_strcpy(arr, "hello");
    printf("%s\n", arr);
    return 0;
}

// https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strcpy.c
