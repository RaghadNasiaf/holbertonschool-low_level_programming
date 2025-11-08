#include "variadic_functions.h"

/**
 * print_numbers - prints numbers followed by a new line
 * @separator: string printed between numbers (can be NULL)
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
