#include <stdio.h>
char *my_strstr(const char *str, const char *substr);

void find_str(char const *str, char const *substr)
{
    char *pos = my_strstr(str, substr);
    if (pos)
    {
        printf("found the string '%s' in '%s' at position: %ld\n", substr, str, pos - str);
    }
    else
    {
        printf("the string '%s' was not found in '%s'\n", substr, str);
    }
}

int main(void)
{
    char *str = "A";
    find_str(str, "ABC");
    return 0;
}

char *my_strstr(const char *str, const char *substr)
{
    // size_t l = 0;
    // char* tmp = (char*) substr;
    // for(; *tmp; tmp++, l++){
    //     // get substr len
    // }

    // for (;*str; str++) {
    //     char* s = (char*) str;
    //     char* ss = (char*) substr;
    //     char* end = s + l;
    //     for (; s < end; s++, ss++) {
    //         if (*s != *ss) break;
    //     }
    //     if (s == end) return (char*) str;
    // }
    // return NULL;

    for (; *str; str++)
    {
        char *s = (char *)str;
        char *ss = (char *)substr;
        for (; *s && *ss; s++, ss++)
        {
            if (*s != *ss)
                break;
        }
        if (!*ss)
            return (char *)str;
    }
    return NULL;
}