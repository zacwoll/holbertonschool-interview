#include "search_algos.h"

/**
 * binary_search_recur - recursively uses binary search
 * @array: array to be searched
 * @low: lower bound of binary search
 * @high: higher bound of binary search
 * @value: key to search for
 * Return: index of value of -1
 */
int binary_search_recur(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	for (mid = low, printf("Searching in array: "); mid <= high;
		mid++)
	printf("%d%s", array[mid], mid == high ? "\n" : ", ");
	mid = low + (high - low) / 2;

	if (low == high)
	{
		if (array[low] == value)
			return (low);
		else
			return (-1);
	}

	if (array[mid] < value)
		return (binary_search_recur(array, mid + 1, high, value));
	else if (array[mid] > value)
		return (binary_search_recur(array, low, mid, value));
	else if (low != mid && (array[mid - 1] == value))
		return (binary_search_recur(array, low, mid, value));
	else
		return (mid);
}

/**
 * advanced_binary - binary search but the first index
 * @array: *ptr to int array
 * @size: size of int array
 * @value: key to search for
 * Return: first index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_search_recur(array, 0, size - 1, value));
}