#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root node of the heap
 *
 * Return: value stored in root node, or 0 if function fails
 **/

int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);
	return ((*root)->n);
}
