#include "sort.h"


/**
 * heap_sort - implement heap sort
 *@array: data of integers to sort
 *@size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	if (size < 2 || array == NULL)
		return;

	heapify(array, size);

	while (end > 0)
	{
		swap(array, size, 0, end);
		siftDown(array, size, 0, --end);
	}
}

/**
 * heapify - put elements of array in heap order
 *@array: data to modify
 *@size: size of array
 */
void heapify(int *array, size_t size)
{
	int start = (size / 2) - 1;

	while (--start >= 0)
		siftDown(array, size, start, size - 1);
}

/**
 * siftDown - Repairs heap
 *@array: data to modify
 *@size: size of array
 *@start: start index of array
 *@end: end index of array
 */
void siftDown(int *array, size_t size, int start, int end)
{
	int left = start * 2 + 1;
	int right = left + 1;
	int max = start;

	if (left <= end && array[left] > array[max])
		max = left;
	if (right <= end && array[right] > array[max])
		max = right;
	if (max == start)
		return;

	swap(array, size, start, max);
	siftDown(array, size, max, end);
}

/**
 * swap - swap values in array at indecies A and B
 *@array: data to modify
 *@size: size of array
 *@indexA: start index of array
 *@indexB: end index of array
 */
void swap(int *array, size_t size, int indexA, int indexB)
{
	int temp = array[indexA];

	array[indexA] = array[indexB];
	array[indexB] = temp;
	print_array(array, size);
}