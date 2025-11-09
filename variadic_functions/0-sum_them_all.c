#include "variadic_functions.h"
#include <stdio.h>

/**
 * sum_them_all - returns the sum of all parameters
 * @n: number of arguments
 * Return: sum or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(ap, n);
	i = 0;
	while (i < n)
	{
		sum += va_arg(ap, int);
		i++;
	}
	va_end(ap);

	return (sum);
}
