#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - allocates a 2D array of ints, initialized to 0
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to 2D array, or NULL on failure/invalid size
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = (int **)malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			/* free already-allocated rows then the rows array */
			int k;

			for (k = 0; k < i; k++)
				free(grid[k]);
			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++)
			grid[i][j] = 0;
	}

	return (grid);
}
