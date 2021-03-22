#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>


void preOrder(avl_t *node)
{
	if (node == NULL)
		return;
	printf("%d ", node->n);
	preOrder(node->left);
	preOrder(node->right);
}

avl_t *array_to_avl_util(int *array, avl_t *parent, size_t start, size_t end)
{
	avl_t *node;
	size_t mid;
	int data;

	/* Base Case */
	if (start > end)
	{
		return (NULL);
	}

	/* Get the middle element and make it root */
	mid = (start + end) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	data = array[mid];
	node->n = data;
	node->parent = parent;

	if (end == 0)
	{
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (!(start + mid - 1 > start + mid))
		node->left = array_to_avl_util(array, node, start, mid - 1);
	node->right = array_to_avl_util(array, node, mid + 1, end);
	return (node);
}

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array)
		return (NULL);

	tree = array_to_avl_util(array, NULL, 0, size-1);
	return (tree);
}