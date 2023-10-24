#include "lists.h"
#include <stdio.h>

/**
 * print_listint - a function that prints all the integers of a list.
 * @h: pointer to the head of the list.
 *
 * Return: the number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t node_count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        node_count++;
        h = h->next;
    }

    return node_count;
}