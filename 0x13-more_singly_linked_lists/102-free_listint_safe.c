#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t linked list.
 * @h: double pointer to the start of the list.
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t num = 0;
    long int diff;
    listint_t *temp;

    if (!h || !*h)
        return (0);

    while (*h)
    {
        diff = *h - (*h)->next;
        if (diff > 0)
        {
            temp = (*h)->next;
            free(*h);
            *h = temp;
            num++;
        }
        else
        {
            free(*h);
            *h = NULL;
            num++;
            break;
        }
    }
    *h = NULL;

    return (num);
}