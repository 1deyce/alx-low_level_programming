#include "lists.h"

/**
 * free_listint2 - frees a listint_t list and sets the head to NULL.
 * @head: double pointer to the start of the list.
 *
 * Return: void.
 */
void free_listint2(listint_t **head)
{
    /* declare a temporary node */
    listint_t *temp;

    /* verify that head and *head are not NULL */
    if (head != NULL && *head != NULL)
    {
        /* go through the list */
        while (*head != NULL)
        {
            /* set temp to head */
            temp = *head;
            /* move head to next node */
            *head = (*head)->next;
            /* free temp */
            free(temp);
        }
        /* set head to NULL */
        *head = NULL;
    }
}