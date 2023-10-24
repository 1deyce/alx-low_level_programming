#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: double pointer to the start of the list.
 *
 * Return: a pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *next;

    while (*head != NULL)
    {
        next = (*head)->next; /* store the next node */
        (*head)->next = prev; /* reverse the link */
        prev = *head; /* move pointers one position ahead */
        *head = next;
    }
    *head = prev;

    return (*head);
}