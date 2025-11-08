#include "main.h"

/**
 * _strpbrk - locate first occurrence in s of any byte from accept
 * @s: input string to scan
 * @accept: set of accepted bytes
 *
 * Return: pointer to the first matching byte in s, or NULL if none
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;

	while (*s)
	{
		p = accept;
		while (*p)
		{
			if (*s == *p)
				return (s);
			p++;
		}
		s++;
	}
	return ((void *)0);
}
