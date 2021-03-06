#include <stdio.h>
#include <stdbool.h>
#include "slide_line.h"

/**
 * rev_list - reverses list for right side calculation
 * @line: line to be reversed
 * @size: size of the list
 */
void rev_list(int *line, size_t size)
{
	int temp = 0, i, j;

	for (i = 0, j = size - 1; i < j; i++, j--)
	{
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}

/**
 * slide_line - function to slide values to the left inside line
 * @line: array of values
 * @size: size of line
 * @direction: 1 or -1, for L and R respectively
 * Return: 1 or 0 if function succeeded/failed
 */
int slide_line(int *line, size_t size, int direction)
{
	bool merged_last = false;
	int start = 0, end = size - 1, val, i, j;

	if (direction == -1)
	{
		rev_list(line, size);
	}
	for (i = start; i <= end; i++)
	{
		val = line[i];
		for (j = i - 1; j >= start && j <= end; j -= 1)
		{
			if (line[j] == val && merged_last == false)
			{
				line[i] = 0;
				line[j] += val;
				val = line[j];
				merged_last = true;
			} else if (line[j] > 0)
			{
				line[i] = 0;
				line[j + 1] = val;
				merged_last = false;
				start++;
				break;
			} else if (j == start)
			{
				line[j] = line[i];
				line[i] = 0;
			}
		}
	}
	if (direction == -1)
		rev_list(line, size);
	return (1);
}
