#include "search.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    skiplist_t *list, *res;
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    list = create_skiplist(array, size);
    print_skiplist(list);

    res =  linear_skip(list, 53);
    printf("Found %d at index: %lu\n\n", 53, (unsigned long) res->index);
    res =  linear_skip(list, 2);
    printf("Found %d at index: %lu\n\n", 2, (unsigned long) res->index);
    res =  linear_skip(list, 999);
    printf("Found %d at index: %p\n", 999, (void *) res);

    free_skiplist(list);
    return (EXIT_SUCCESS);
}