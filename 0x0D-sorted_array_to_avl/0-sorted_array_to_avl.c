#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer to root node of AVL tree created, or NULL on failure
 **/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (build_tree(array, 0, size - 1, NULL));
}

/**
 * build_tree - recursively builds an AVL tree from a sorted array
 * @array: pointer to first element of array to be converted
 * @start: index of array to start at
 * @end: index of array to end at
 * @prev_root: parent node of current position
 *
 * Return: pointer to root node of AVL tree created, or NULL on failure
 **/

avl_t *build_tree(int *array, int start, int end, avl_t *prev_root)
{
	int mid;
	avl_t *root;

	if (start > end || start < 0)
		return (NULL);
	mid = (start + end) / 2;
	root = make_node(array[mid]);
	if (!root)
		return (NULL);
	root->parent = prev_root;
	root->left = build_tree(array, start, mid - 1, root);
	root->right = build_tree(array, mid + 1, end, root);
	return (root);
}

/**
 * make_node -makes a new node with n equal to data
 * @data: number to store as n on new node
 *
 * Return: pointer to new node, or NULL on failure
 **/

avl_t *make_node(int data)
{
	avl_t *new_node = malloc(sizeof(avl_t) * 1);

	if (!new_node)
		return (NULL);

	new_node->n = data;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}