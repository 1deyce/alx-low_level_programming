#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: double pointer to the start of the list.
 * @idx: index of the list where the new node should be added.
 * @n: data for the new node.
 *
 * Return: address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node;
    listint_t *temp = *head;
    unsigned int i;

    /* allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return (NULL);
    }

    /* put data in the new node */
    new_node->n = n;

    /* if idx is 0, insert the node at the start of the list */
    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* go to the node before the index */
    for (i = 1; i < idx; i++)
    {
        if (temp == NULL)  /* if we reach the end of the list before the index */
        {
            free(new_node);
            return (NULL);
        }
        temp = temp->next;
    }

    /* insert the new node */
    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);
}