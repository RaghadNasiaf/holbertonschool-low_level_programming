#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: pointer to the string
 *
 * Return: pointer to the string
 */
char *cap_string(char *s)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	/* Capitalize first character if needed */
	if (s[i] >= 'a' && s[i] <= 'z')
		s[i] -= ('a' - 'A');

	for (i = 1; s[i] != '\0'; i++)
	{
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i - 1] == sep[j] && (s[i] >= 'a' && s[i] <= 'z'))
			{
				s[i] -= ('a' - 'A');
				break;
			}
		}
	}

	return (s);
}
