#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

void swaps(heap_t *n1, heap_t *n2, int left);
void swap(heap_t *n1, heap_t *n2);
int height(heap_t *root);
heap_t *parent(heap_t *root);

/**
 * heap_insert - insert a node into a max heap
 * @root: root node
 * @value: what value to add
 * Return: newly added node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *is, *new;
	/* check for nothing */
	if (!root)
		return (NULL);
	/* make a single node */
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	is = parent(*root);
	new = binary_tree_node(is, value);

	if (!(is->left))
		is->left = new;
	else
		is->right = new;
	/* clean up */
	while (new->parent && new->parent->n < value)
	{
		swap(new->parent, new);
	}
	while ((*root)->parent)
	{
		*root = (*root)->parent;
	}
	return (new);
}
/**
 * swaps - assist swap function
 * @n1: one node
 * @n2: another node
 * @left: check id the child is leftward
 **/
void swaps(heap_t *n1, heap_t *n2, int left)
{
	heap_t *temp;

	if (!left)
	{
		n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = n1;
		temp = n1->left;
		n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = temp;
		if (n2->left)
			n2->left->parent = n2;
	}
	else
	{
		n1->left = n2->left;
		if (n1->left)
			n1->left->parent = n1;
		n2->left = n1;
		temp = n1->right;
		n1->right = n2->right;
		if (n1->right)
			n1->right->parent = n1;
		n2->right = temp;
		if (n2->right)
			n2->right->parent = n2;
	}
}

/**
 * swap - to swap two nodes
 * @n1: the 1st node to swap
 * @n2: The 2nd node to swap - child
 */
void swap(heap_t *n1, heap_t *n2)
{
	char left = 0;

	n2->parent = n1->parent;

	if (n1->left == n2)
		left = 1;

	if (n1->parent)
	{
		if (n1->parent->right == n1)
			n1->parent->right = n2;
		else
			n1->parent->left = n2;
	}

	n1->parent = n2;

	swaps(n1, n2, left);
}

/**
 * height - the height of the tree
 * @root: root node
 * Return: height of the tree
 **/
int height(heap_t *root)
{
	int height_left, height_right;
	/* no height? */
	if (!root)
		return (0);

	height_left = height(root->left) + 1;
	height_right = height(root->right) + 1;

	return (height_left > height_right ? height_right : height_left);
}

/**
 * parent - Finds the parent node
 * @root: root node
 * Return: found parent
 **/
heap_t *parent(heap_t *root)
{
	while (root->right && root->left)
	{
		if (height(root->left) == height(root->right))
			root = root->left;
		else
			root = root->right;
	}
	return (root);
}