# Heap sort
Write a function that sorts an array of integers in ascending order using the Heap sort algorithm

- Prototype: void heap_sort(int *array, size_t size);
- You must implement the sift-down heap sort algorithm
- You’re expected to print the array after each time you swap two elements (See example below)
Write in the file 0-O, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case
## More Info
For this project you are given the following print_array function:
```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```