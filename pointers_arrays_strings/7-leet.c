#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the resulting string
 */
char *leet(char *s)
{
	char from[] = "aAeEoOtTlL";
	char to[]   = "4433007711";
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; from[j] != '\0'; j++)
		{
			if (s[i] == from[j])
			{
				s[i] = to[j];
				break;
			}
		}
	}
	return (s);
}

