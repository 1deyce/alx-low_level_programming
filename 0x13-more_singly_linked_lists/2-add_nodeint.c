#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 * @head: double pointer to the start of the list.
 * @n: the integer to be included in the new node.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    /* create a new node */
    listint_t *new_node = malloc(sizeof(listint_t));

    /* check if memory allocation failed */
    if (new_node == NULL)
        return NULL;

    /* initialize the new node */
    new_node->n = n;
    new_node->next = *head;

    /* set the new node as the head of the list */
    *head = new_node;

    return new_node;
}