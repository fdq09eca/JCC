# Note

- 2d array formula = `rowIdx * numCol + colIdx`
- `fread` **does not** return the read value, see [doc](https://en.cppreference.com/w/cpp/io/c/fread).
- 2's complement char `1 byte`
- unsigned char
- POSIX
- `size_t` is `unsiged`, `printf` when it is 32bit: `%u`; 64bit: `%ull`
- x86, x64

## ex

- [x] str_int_parser
- [x] int_str_convert

The following ex follow [cppreference.com](https://en.cppreference.com/w/c/string/byte):

- [x] [my_strcpy](https://en.cppreference.com/w/c/string/byte/strcpy)
- [x] [my_strncpy](https://en.cppreference.com/w/c/string/byte/strncpy)
- [x] [strlen](https://en.cppreference.com/w/c/string/byte/strlen)
- [x] [my_strcat](https://en.cppreference.com/w/c/string/byte/strcat)[^p1] -> [fbsd_strcat](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strcat.c)
- [x] [my_strdup](https://en.cppreference.com/w/c/string/byte/strdup) ->  [freebsd_strdup](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strdup.c)
- [ ] my_strndup
- [ ] my_strcmp
- [ ] my_strncmp
- [ ] strchr
- [ ] strrchr
- [ ] strstr
- [ ] **strrstr**
- [ ] **strcasestr**/ **stristr** (window)
- [ ] **strcaseRstr**/ **striRstr** (window)
- [ ] strtok [^1]
- [ ] memch
- [ ] memset
- [ ] memcpy
- [ ] memmove

[^1]: `static buffer`
[^p1]: Instead of doing the copy, i was thinking put the `char* src` at the `char* dest`'s null terminator position.. but seems it is worng, is it conceptual problem? 
## ref

1. [freebsd](https://github.com/freebsd/freebsd-src/tree/master/lib/libc/string)
2. [strlen](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strlen.c#L111)
