#include "binary_trees.h"

/**
 * balance_left - balances left side
 * @node: pointer to temp node
 * Return: root of tree
 */
avl_t *balance_left(avl_t *node)
{
	avl_t *ret;
	int bal;

	if (!node->left)
		return (NULL);
	bal = binary_tree_balance(node->left);
	if (bal > 0)
	{
		ret = binary_tree_rotate_right(node);
		return (ret);
	}
	binary_tree_rotate_left(node->left);
	ret = binary_tree_rotate_right(node);
	return (ret);
}

/**
 * balance_right - balances left side
 * @node: pointer to temp node
 * Return: root of tree
 */
avl_t *balance_right(avl_t *node)
{
	avl_t *ret;
	int bal;

	if (!node->right)
		return (NULL);
	bal = binary_tree_balance(node->right);
	if (bal > 0)
	{
		ret = binary_tree_rotate_right(node);
		return (ret);
	}
	binary_tree_rotate_left(node->right);
	ret = binary_tree_rotate_right(node);
	return (ret);
}

/**
 * rebalance - rebalance AVL tree
 * @node: pointer to node to rebalance
 * @tree: double pointer to root of tree
 * Return: pointer to input node
 */
avl_t *rebalance(avl_t *node, avl_t **tree)
{
	avl_t *tmp, *root;
	int bal;

	tmp = node;
	while (tmp)
	{
		bal = binary_tree_balance(tmp);
		if (bal > 1)
		{
			root = balance_left(tmp);
			if (root)
				*tree = root;
		}
		else if (bal < -1)
		{
			root = balance_right(tmp);
			if (root)
				*tree = root;
		}
		tmp = tmp->parent;
	}
	return (node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *av, *node;

	if (!tree)
		return (NULL);
	av = binary_tree_node(*tree, value);
	if (!*tree)
	{
		return (*tree = av);
	}
	node = *tree;
	while (node)
	{
		if (value == node->n)
			return (free(av), NULL);
		if (value < node->n)
		{
			if (!node->left)
			{
				av->parent = node;
				node->left = av;
				return (rebalance(node, tree));
			}
			node = node->left;
		} else
		{
			if (!node->right)
			{
				av->parent = node;
				node->right = av;
				return (rebalance(node, tree));
			}
			node = node->right;
		}
	}
	return (free(av), NULL);
}

int main(void)
{
    avl_t *root;
    avl_t *node;

    root = NULL;
    node = avl_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 402);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 12);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 46);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 128);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
	node = avl_insert(&root, 256);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    /*
	node = avl_insert(&root, 512);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = avl_insert(&root, 50);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    */
	return (0);
}