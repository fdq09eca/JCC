# ex

- [x] str_int_parser
- [x] int_str_convert

The following ex follow [cppreference.com](https://en.cppreference.com/w/c/string/byte):

- [x] [my_strcpy](./my_strcpy.c): [cppref](https://en.cppreference.com/w/c/string/byte/strcpy), [fdsb_strcpy](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strcpy.c)
- [x] [my_strncpy](./my_strncpy.c): [cppref](https://en.cppreference.com/w/c/string/byte/strncpy), [fbsd_strncpy](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strncpy.c)
- [x] [my_strlen](./my_strlen.c): [cppref](https://en.cppreference.com/w/c/string/byte/strlen), [fbsd_strlen](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strlen.c#L111)
- [x] [my_strcat](./my_strcat.c)[^p1] [^a1]: [cppref](https://en.cppreference.com/w/c/string/byte/strcat) [fbsd_strcat](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strcat.c)
- [x] [my_strdup](./my_strdup.c): [cppref](https://en.cppreference.com/w/c/string/byte/strdup), [freebsd_strdup](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strdup.c)
- [x] [my_strndup](./my_strndup.c): [cppref](https://en.cppreference.com/w/c/string/byte/strndup), [freebsd_strndup](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strndup.c)
- [x] [my_strcmp](./my_strcmp.c): [cppref](https://en.cppreference.com/w/c/string/byte/strcmp), [freebsd_strcmp](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strcmp.c)
- [x] [my_strncmp](./my_strncmp.c): [cppref](https://en.cppreference.com/w/c/string/byte/strncmp), [freebsd_strncmp](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strncmp.c)
- [x] [my_strchr](./my_strchr.c): [cppref](https://en.cppreference.com/w/c/string/byte/strchr), [freebsd_strchr](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strchr.c)
- [x] [my_strrchr](./my_strrchr.c): [cppref](https://en.cppreference.com/w/c/string/byte/strrchr), [freebsd_strrchr](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strrchr.c)
- [x] [my_strstr](./my_strstr.c): [cppref](https://en.cppreference.com/w/c/string/byte/strstr), [freebsd_strstr](https://github.com/freebsd/freebsd-src/blob/master/lib/libc/string/strstr.c)
- [x] [my_strrstr](./my_strrstr.c): noref.
- [ ] **strcasestr**/ **stristr** (window)
- [ ] **strcaseRstr**/ **striRstr** (window)
- [ ] strtok [^1]
- [ ] memchr
- [ ] memset
- [ ] memcpy
- [ ] memmove

[^1]: `static buffer`
[^p1]: Instead of doing the copy, I was thinking put the `char* src` at the `char* dest`'s null terminator position (as if linked list) but seems it is worng, why is it?
[^a1]: because wrong type. `*dest` is `char` cannot be char pointer.


# Note

- 2d array formula = `rowIdx * numCol + colIdx`
- `fread` **does not** return the read value, see [doc](https://en.cppreference.com/w/cpp/io/c/fread).
- 1's complement, 2's complement
- POSIX
- Corss platform matters
  - `size_t` is `unsiged int type`
    - `printf` when it is 32bit (4 byte): `%u`; 64bit (8 byte): `%ull`
    - see Jason's [youtube ref](https://www.youtube.com/watch?v=JiUfvzd4eQM)
  - `unsigned char`
- x86, x64
- `gcc`: GNU C Compiler
  - `gcc -o my_strcat my_strcat.c my_strcpy.c` compile 2 `.c` together, only 1 `main(){}`.
- `while (*s++){}` is different from `while (*s) {s++;}`

*DEBUG: print out the pointer, deref.*

```c
for (;str >= s; str-- ) {
        printf(" c = %d\n", *str);
}
```

*RESULT*

```sh
~/Documents/JCC(ex*) » make my_strrchr && ./my_strrchr                                                                                                                                          macone@Macs-MBP
cc     my_strrchr.c   -o my_strrchr
 c = 0
 c = 7
 c = 55
s0: 0x7ffeea48d59d, 7: 0x7ffeea48d59d
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
~/Documents/JCC(ex*) » make my_strrchr && ./my_strrchr                                                                                                                                          macone@Macs-MBP
cc     my_strrchr.c   -o my_strrchr
 c = 7
 c = 55
s0: 0x7ffee3a5959d, 7: 0x7ffee3a5959d
```

- null terminator concept: **do not** rely on str length. 
