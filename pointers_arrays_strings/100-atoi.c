#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value
 *
 * Note: Build as a negative number to handle INT_MIN safely.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int result = 0; /* keep negative while parsing */

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
				sign = -sign;
			else if (s[i] >= '0' && s[i] <= '9')
			{
				started = 1;
				result = -(s[i] - '0'); /* start negative */
			}
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
				result = (result * 10) - (s[i] - '0'); /* stay negative */
			else
				break;
		}
		i++;
	}

	if (!started)
		return (0);

	if (sign > 0)
		return (-result);
	return (result);
}
