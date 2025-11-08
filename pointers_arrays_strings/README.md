# Pointers, Arrays and Strings (Even More)

This project implements selected libc-like helpers without using the standard C library, following Betty style.

- `_memset(char *s, char b, unsigned int n)`: fills memory with a constant byte.
- `_memcpy(char *dest, char *src, unsigned int n)`: copies memory area.

## Build (local tests)
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-memset.c -o 0-memset
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-memcpy.c -o 1-memcpy

## Author
RaghadNasiaf <naseefraghad@gmail.com>
