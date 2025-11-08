#include "variadic_functions.h"

/**
 * print_strings - prints strings followed by a new line
 * @separator: string printed between strings (can be NULL)
 * @n: number of strings
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	const char *s;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, const char *);
		if (s)
			printf("%s", s);
		else
			printf("(nil)");

		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}
