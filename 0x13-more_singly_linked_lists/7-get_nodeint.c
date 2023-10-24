#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the start of the list.
 * @index: index of the node to return, starting at 0.
 *
 * Return: nth node of a listint_t linked list.
 *         If the node does not exist, return NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    /* go through the list */
    for (i = 0; head; i++)
    {
        /* if the current node is the one we are looking for, return it */
        if (i == index)
        {
            return (head);
        }

        /* move to the next node */
        head = head->next;
    }

    /* if we get here, the node doesn't exist */
    return (NULL);
}