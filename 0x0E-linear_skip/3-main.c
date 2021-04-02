#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("Found at index: %p\n", (void *) linear_skip(NULL, 0));
	return (0);
}