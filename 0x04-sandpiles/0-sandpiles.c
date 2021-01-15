#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: the grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * count_adj_unstables - counts adjacent unstable grid cells
 * @grid1: grid operating on
 * @i: first index
 * @j: second index
 * Return: Sum of unstable adjacent cells
 */
int count_adj_unstables(int grid1[3][3], int i, int j)
{
	int adj_sum = 0;

	if (i > 0 && grid1[i - 1][j] > 3)
		adj_sum++;
	if (i < 2 && grid1[i + 1][j] > 3)
		adj_sum++;
	if (j > 0 && grid1[i][j - 1] > 3)
		adj_sum++;
	if (j < 2 && grid1[i][j + 1] > 3)
		adj_sum++;
	return (adj_sum);
}

/**
 * add_grids - adds my multiple 3x3 grids together
 * @grid1: first grid, and target for summation
 * @grid2: second grid
 * @grid3: third grid
 */
void add_grids(int grid1[3][3], int grid2[3][3], int grid3[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j] + grid3[i][j];
		}
	}
}

/**
 * sandpiles_sum - generates the stable sum of two 3x3 sandpiles
 * @grid1: the first sandpile 3x3 grid
 * @grid2: the second sandpile 3x3 gridd
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, adj_sum;
	int topple[3][3], adj_unstable_grid[3][3];
	bool isStable = true;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				isStable = false;
		}
	}
	while (!isStable)
	{
		isStable = true;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					isStable = false;
					topple[i][j] = -4;
				}
				else
					topple[i][j] = 0;
				adj_sum = count_adj_unstables(grid1, i, j);
				adj_unstable_grid[i][j] = adj_sum;
			}
		}
		if (!isStable)
			print_grid(grid1);
		add_grids(grid1, topple, adj_unstable_grid);
	}
}

