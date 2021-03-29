# 0x0E. Linear search in skip list
## Task: Search for value in skip list
Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a skip list.

### search.h header file
```
#ifndef SEARCH_H
#define SEARCH_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * struct skiplist_t - linked list with skip lane
 *
 * @n: Integer stored in the node
 * @index: Index of the node in the list
 * @express: Pointer to the next express node
 * @next: Pointer to the next node
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
```