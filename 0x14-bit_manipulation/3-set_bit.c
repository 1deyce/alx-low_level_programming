#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: A pointer to the bit integer.
 * @index: The index to set the bit at.
 *
 * Return: If an error occurred - -1. Otherwise - 1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= (sizeof(*n) * 8))
    {
        return (-1);
    }

    *n |= 1 << index;

    return (1);
}