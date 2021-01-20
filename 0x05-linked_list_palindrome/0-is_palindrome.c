#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"

/**
 * helper - recursive helper fnc for is_palindrome
 * @slow - double ptr to check front of list slowly
 * @fast - ptr to end of list working backwards
 * Return: 1 if passes palindromic checks else 0
 */
int helper(listint_t **slow, listint_t *fast)
{
	if (fast == NULL)
		return (1);
	if (!helper(slow, fast->next) || fast->n != (*slow)->n)
		return (0);
	*slow = (*slow)->next;
	return (1);
}

/**
 * is_palindrome - checks if singly linked list is palindromic
 * @head - head of linked list
 * Return: 1 if palindromic else 0
 */
int is_palindrome(listint_t **head) {
    if (*head == NULL)
        return (1);
    return (helper(head, *head));
}
