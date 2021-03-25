#include "binary_trees.h"

/**
 * sorted_array_to_avl - convert array to avl
 * @array: sorted array
 * @size: size of the array
 *
 * Return: pointer to the root node of the avl tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int isEven = !((int)size % 2);
	avl_t *root, *temp = NULL;
	avl_t *tail = malloc(sizeof(avl_t));

	if (isEven)
	{
		tail->n = array[--size];
		tail->parent = NULL;
		tail->left = NULL;
		tail->right = NULL;
	}
	root = build_avl(array, size);
	temp = root;
	setParents(root->left, root);
	setParents(root->right, root);

	if (isEven)
	{
		while (temp->right != NULL)
			temp = temp->right;
		tail->parent = temp;
		temp->right = tail;
	}

	return (root);
}

/**
 * setParents - recursivly set parents of a binary tree
 * @node: root node of a sub-tree
 * @parent: parent of node
 *
 * Return: void
 */

void setParents(avl_t *node, avl_t *parent)
{
	if (!node)
		return;

	node->parent = parent;

	setParents(node->left, node);
	setParents(node->right, node);
}

/**
 * build_avl - recursivly build avl with given array
 * @array: given int array
 * @size: size of array
 *
 * Return: Root node of built avl
 */

avl_t *build_avl(int *array, size_t size)
{
	avl_t *root;
	int i, middle;
	int range = ((int)size % 2 == 0) ? (size / 2) - 1 : size / 2;
	int *left = malloc(sizeof((size / 2)) * sizeof(int));
	int *right = malloc(sizeof((size / 2)) * sizeof(int));

	root = malloc(sizeof(avl_t));
	if (array == NULL || size < 1 || root == NULL)
		return (NULL);

	middle = array[range];
	if (middle == 0)
		return (NULL);

	for (i = 0; i < range; i++)
	{
		if ((int)size % 2)
			left[i] = array[i];
		else
			left[i] = array[i - 1];
	}

	for (i = 0; i < (int)size / 2; i++)
	{
		if ((int)size % 2 == 0)
			right[i] = array[i + (size / 2)];
		else
			right[i] = array[i + 1 + (size / 2)];
	}

	root->n = middle;
	root->parent = NULL;
	root->left = build_avl(left, (size / 2));
	root->right = build_avl(right, (size / 2));

	free(left);
	free(right);
	return (root);
}