#include "function_pointers.h"

/**
 * print_name - prints a name using a callback function
 * @name: pointer to name string
 * @f: pointer to a function that takes a char* and returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == (void *)0 || f == (void *)0)
		return;

	f(name);
}
