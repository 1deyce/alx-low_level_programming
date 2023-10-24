#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list.
 * @head: pointer to the start of the list.
 *
 * Return: sum of all the data (n) of a listint_t linked list.
 *         If the list is empty, return 0.
 */
int sum_listint(listint_t *head)
{
    int sum = 0;

    /* go through the list */
    while (head)
    {
        /* add the current node's data to the sum */
        sum += head->n;

        /* move to the next node */
        head = head->next;
    }

    /* return the sum */
    return (sum);
}