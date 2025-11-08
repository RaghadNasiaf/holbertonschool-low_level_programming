#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array of chars initialized with a specific char
 * @size: number of elements to allocate
 * @c: char to fill the array with
 *
 * Return: pointer to the allocated array, or NULL on failure or if size == 0
 */
char *create_array(unsigned int size, char c)
{
	char *buf;
	unsigned int i;

	if (size == 0)
		return (NULL);

	buf = (char *)malloc(size * sizeof(char));
	if (buf == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		buf[i] = c;

	return (buf);
}
