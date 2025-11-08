#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);

/* Pointers/Arrays/Strings (even more) */
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
void print_chessboard(char (*a)[8]);
void print_diagsums(int *a, int size);

/* From the earlier set in this directory */
char *leet(char *s);

#endif /* MAIN_H */
