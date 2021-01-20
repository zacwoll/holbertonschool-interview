#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lists.h"

/**
 * helper - recursive helper fnc for is_palindrome
 * @current - ptr sent to end of list to work backwards
 * @head - head of list
 * @isPal - boolean palindromic tracker
 * Return: ptr to next node to be checked
 */
listint_t* helper(listint_t *current, listint_t *head, bool* isPal)
{
    if(current == NULL)
    {
        return head;
    }
    else
    {
        head = helper(current->next, head, isPal);
        if(*isPal)
        {
            if(current->n != head->n)
            {
                *isPal = false;
                return head->next;
            }
            else
            {
                return head->next;
            }
        }
    }
    return head;
}

/**
 * is_palindrome - checks if singly linked list is palindromic
 * @head - head of linked list
 * Return: 1 if palindromic else 0
 */
int is_palindrome(listint_t **head) {
    bool* isPal = malloc(sizeof(bool));
    *isPal = true;
    helper(*head, *head, isPal);
    if (isPal)
        return 1;
    else
        return 0;
}