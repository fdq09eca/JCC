#include <stdio.h>

char *my_strncpy(char *dest, char *src, int n)
{

    char *rtn = dest;
    while (n--)
    {
        *dest = *src ? *src : 0;
        dest++;
        src++;
    }

    return rtn;
}

int main()
{
    char src[] = "hi";
    char dest[6] = "abcdef";  // no null terminator
    my_strncpy(dest, src, 5); // writes five characters 'h', 'i', '\0', '\0', '\0' to dest
    printf("strncpy(dest, src, 5) to a 6-byte dest gives : ");
    for (size_t n = 0; n < sizeof dest; ++n)
    {
        char c = dest[n];
        c ? printf("'%c' ", c) : printf("'\\0' ");
    }
    printf("\nstrncpy(dest2, src, 2) to a 2-byte dst gives : ");
    char dest2[2];
    my_strncpy(dest2, src, 2); // truncation: writes two characters 'h', 'i', to dest2
    for (size_t n = 0; n < sizeof dest2; ++n)
    {
        char c = dest2[n];
        c ? printf("'%c' ", c) : printf("'\\0' ");
    }
    printf("\n");
}