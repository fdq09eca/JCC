# Note

- 2d array formula = `rowIdx * numCol + colIdx`
- `fread` **does not** return the read value, see [doc](https://en.cppreference.com/w/cpp/io/c/fread).
- 2's complement char `1 byte`
- unsigned char
- POSIX
- `size_t` is `unsiged`, `printf` when it is 32bit: `%u`; 64bit: `%ull`
- x86, x64

## ex

The following ex follow [cppreference.com](https://en.cppreference.com/w/c/string/byte):

- [x] str_int_parser
- [x] int_str_convert
- [x] my_strcpy
- [ ] my_strncpy
- [x] strlen
- [ ] my_strcat
- [ ] my_strdup
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

## ref

1. [freebsd](https://github.com/freebsd/freebsd-src/tree/master/lib/libc/string)
2. [strlen](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strlen.c#L111)
