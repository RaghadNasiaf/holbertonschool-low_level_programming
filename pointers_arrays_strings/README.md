# Pointers, Arrays and Strings (and Even More)
This project implements selected libc-like helper functions without using the C standard library, following Betty style.

## Build (local tests)
# Use the corresponding main.c for each task when testing locally.
# Where `_putchar` is required, include a local `_putchar.c` for testing only.

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-memset.c -o 0-memset
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-memcpy.c -o 1-memcpy
# ...
