#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/**
 * createCarpet - creates a 2D string array of side_length
 * @side_length: side_length of carpet
 * Return: Char ** to carpet
 */
char **createCarpet(int side_length)
{
	int i, j;
	char **carpet;

	carpet = malloc(sizeof(char *) * side_length);
	for (i = 0; i < side_length; i++)
	{
		carpet[i] = malloc(sizeof(char) * (side_length + 1));
		for (j = 0; j < side_length; j++)
			carpet[i][j] = '#';
		carpet[i][j] = '\0';
	}
	return (carpet);
}

/**
 * freeCarpet - frees a carpet previously set up
 * @carpet: double pointer to carpet
 */
void freeCarpet(char **carpet)
{
	int i, length = strlen(carpet[0]);

	for (i = 0; i < length; i++)
		free(carpet[i]);
	free(carpet);
}

/**
 * createNewCarpet - function that iterates on a carpet
 * @old: old carpet of size 1 less than desired at this stage
 * Return: char ** to new carpet
 */
char **createNewCarpet(char **old)
{
	int i, j, k, l, old_length = strlen(old[0]);
	char **new;

	new = createCarpet(old_length * 3);

	for (i = 0; i < old_length; i++)
	{
		for (j = 0; j < old_length; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					if (old[i][j] == ' ')
						new[3 * i + k][3 * j + l] = ' ';
				}
			}
			new[3 * i + 1][3 * j + 1] = ' ';
		}
	}

	freeCarpet(old);
	return (new);
}

/**
 * printCarpet - prints a carpet
 * @carpet: carpet to be printed
 */
void printCarpet(char **carpet)
{
	int height = strlen(carpet[0]);
	int i;

	for (i = 0; i < height; i++)
		printf("%s\n", carpet[i]);
}

/**
 * menger - function to generate and print a sierpinsky carpet of given level
 * @level: level of carpet desired
 */
void menger(int level)
{
	char **carpet = createCarpet(1);
	int i;

	for (i = 0; i < level; i++)
		carpet = createNewCarpet(carpet);

	printCarpet(carpet);
	freeCarpet(carpet);
}
