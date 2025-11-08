#include "main.h"

/**
 * find_sqrt - helper function to find natural sqrt
 * @n: number
 * @i: current guess
 *
 * Return: sqrt or -1
 */
int find_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural sqrt of n
 * @n: number
 *
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}
