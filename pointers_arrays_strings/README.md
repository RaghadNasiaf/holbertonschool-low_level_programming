Pointers, Arrays and Strings (even more)
This project re-implements selected libc-like helpers without using the C standard library,
following Betty style and project constraints.

Functions in this part include:
- _memset
- _memcpy
- _strchr
- _strspn
- _strpbrk
- _strstr

Build example (local test only):
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-strpbrk.c -o 4-strpbrk
