#include "main.h"

/**
 * _strpbrk - locates the first occurrence in s of any of the bytes in accept
 * @s: input string to scan
 * @accept: set of accepted bytes
 *
 * Return: pointer to the first matching byte in s, or 0 if none
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				return (s);
			a++;
		}
		s++;
	}
	return (0);
}
