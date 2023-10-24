#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 *               and returns the head node’s data (n).
 * @head: double pointer to the start of the list.
 *
 * Return: the head node’s data (n).
 */
int pop_listint(listint_t **head)
{
    int n;
    listint_t *temp;

    /* verify that head and *head are not NULL */
    if (head == NULL || *head == NULL)
    {
        return (0);
    }

    /* store the data to return later */
    n = (*head)->n;

    /* store the current head node to free later */
    temp = *head;

    /* move head to the next node */
    *head = (*head)->next;

    /* free the old head node */
    free(temp);

    /* return the stored data */
    return (n);
}