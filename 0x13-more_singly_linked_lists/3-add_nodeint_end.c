#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: double pointer to the start of the list.
 * @n: the integer to be included in the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    /* create a new node */
    listint_t *new_node = malloc(sizeof(listint_t));
    listint_t *last_node = *head;

    /* check if memory allocation failed */
    if (new_node == NULL)
        return NULL;

    /* initialize the new node */
    new_node->n = n;
    new_node->next = NULL;

    /* if the list is empty, set the new node as the head */
    if (*head == NULL)
    {
        *head = new_node;
        return new_node;
    }

    /* traverse to the end of the list */
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    /* add the new node at the end of the list */
    last_node->next = new_node;

    return new_node;
}