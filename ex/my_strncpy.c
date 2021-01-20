#include <stdio.h>

int main()
{
    char dest[100];
    printf("%s\n", my_strncpy(dest, "123456789", 5));
}

char* my_strnspy(char* dest, char* src, int n) {
    
    char* rtn = dest;
    int c = 0;
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    return rtn;
}