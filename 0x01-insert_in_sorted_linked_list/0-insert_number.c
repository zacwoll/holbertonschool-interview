#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts node into singly linked list
 * @head: pointer to head of list
 * @number: value to be inserted
 * Return: pointer to new node or NULL
 */
listint_t *insert_node(listint_t **head, int number) {
    listint_t *new, *current = *head;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);

    new->n = number;

    if (!current || number < current->n) {
        new->next = current;
        *head = new;
        return (new);
    }

    while (current->next && number > current->next->n) {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;

    return (new);
}