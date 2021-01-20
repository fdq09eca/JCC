#include <stdio.h>

void test(int a, int b, int c)
{
    printf("%d %d %d\n", a, b, c);
}

int main()
{
    int i = 0;
    test(i++, i++, i++);
}

// platform specific "Calling Convention"
// window: from right to left >> 2 1 0
// mac: from left to right >> 0 1 2
// https://en.wikipedia.org/wiki/Calling_convention