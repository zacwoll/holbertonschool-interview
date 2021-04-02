#include "search.h"

/**
 * get_end_index - gets last index of list
 * @list: pointer to head of list
 * Return: last index of list
 * Description: Need to print last node, but skips past it
 */
size_t get_end_index(skiplist_t *list)
{
	skiplist_t *former;

	while (list)
	{
		former = list;
			list = list->express;
	}
	list = former;
	while (list)
	{
		former = list;
			list = list->next;
	}
	return (former->index);
}

/**
 * linear_skip - searchs for value in skip list
 * @list: head of list to search through
 * @value: value to be searched for
 * Return: Pointer to Node containing value or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *lower = list;
	size_t end_index = get_end_index(list);

	if (!list)
		return (NULL);
	list = list->express;
	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			(unsigned long) list->index, list->n);
		lower = list;
		list = list->express;
	}
	if (!list || list->n > value)
	{
		if (list)
			end_index = list->index;
		printf("Value found between indexes [%lu] and [%lu]\n",
			(unsigned long) lower->index,
			(unsigned long) end_index);
			printf("Value checked at index [%lu] = [%d]\n",
			(unsigned long) lower->index, lower->n);
			list = lower;
		}
		else if (list->n == value)
		return (list);
		while (list && list->n < value)
		{
			lower = list;
			list = list->next;
			if (list)
				printf("Value checked at index [%lu] = [%d]\n",
				(unsigned long) list->index, list->n);
		}
		if (!list || list->n != value)
			return (NULL);
		return (list);
	}
