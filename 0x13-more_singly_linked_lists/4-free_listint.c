#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to the start of the list.
 *
 * Return: void.
 */
void free_listint(listint_t *head)
{
    /* declare a temporary node */
    listint_t *temp;

    /* go through the list */
    while (head != NULL)
    {
        /* set temp to head */
        temp = head;
        /* move head to next node */
        head = head->next;
        /* free temp */
        free(temp);
    }
}