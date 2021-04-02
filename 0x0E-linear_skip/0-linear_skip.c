#include "search.h"

/**
 * linear_skip - quickly searches linked list
 * @list: head node
 * @value: target value
 *
 * Return: Node with the given target value or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list;
	unsigned long length;

	if (list == NULL)
		return (NULL);
	if (temp->express)
		length = temp->express->index * temp->express->index;

	while (temp->express)
	{
		printf(
			"Value checked at index [%lu] = [%d]\n",
			temp->express->index,
			temp->express->n
		);
		if (temp->n == value)
			return (temp);
		if (temp->express->n > value)
			break;
		temp = temp->express;
	}

	printf(
		"Value found between indexes [%lu] and [%lu]\n",
		temp->index,
		(temp->express) ? temp->express->index : --length
	);

	while (temp)
	{
		printf(
			"Value checked at index [%lu] = [%d]\n",
			temp->index,
			temp->n
		);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}