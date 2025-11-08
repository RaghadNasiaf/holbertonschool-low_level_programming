#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals
 *                  of a square matrix of integers
 * @a: pointer to the first element (casted from int[][])
 * @size: size of the square matrix
 */
void print_diagsums(int *a, int size)
{
	int i;
	long d1 = 0, d2 = 0;

	for (i = 0; i < size; i++)
	{
		d1 += a[i * size + i];
		d2 += a[i * size + (size - 1 - i)];
	}
	printf("%ld, %ld\n", d1, d2);
}
