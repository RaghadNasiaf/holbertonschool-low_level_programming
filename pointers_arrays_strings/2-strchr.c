#include "main.h"

/**
 * _strchr - locate first occurrence of character in string
 * @s: input string to scan
 * @c: character to find
 *
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return ((void *)0);
}
