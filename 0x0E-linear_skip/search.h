#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct skiplist_t
{
	int n;
	size_t index;
	struct skiplist_t *express;
	struct skiplist_t *next;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */