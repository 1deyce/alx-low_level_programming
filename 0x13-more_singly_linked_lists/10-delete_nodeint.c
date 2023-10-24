#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list.
 * @head: double pointer to the start of the list.
 * @index: index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *temp = *head;
    listint_t *next_node;
    unsigned int i;

    /* if the list is empty, return -1 */
    if (temp == NULL)
    {
        return (-1);
    }

    /* if the first node should be removed */
    if (index == 0)
    {
        *head = temp->next; /* change the head to the next node */
        free(temp); /* free the old head */
        return (1);
    }

    /* find the node before the node to be deleted */
    for (i = 1; i < index; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            return (-1);
        }
        temp = temp->next;
    }

    /* if the node to be deleted is NULL, return -1 */
    if (temp->next == NULL)
    {
        return (-1);
    }

    /* set next_node to the node after the node to be deleted */
    next_node = temp->next->next;

    /* delete the node at index */
    free(temp->next);

    /* link the previous node to the next node */
    temp->next = next_node;

    return (1);
}