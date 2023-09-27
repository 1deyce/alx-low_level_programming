#include "main.h"

int is_prime(int n);

/**
 * is_prime_number - checks if an integer is a prime number or not
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, 0 if not
 */
int is_prime_number(int n)
{
    if (n <= 1)
        return 0;
    return is_prime(n);
}

/**
 * is_prime - recursively determines if a number is prime
 * @n: number to evaluate
 *
 * Return: 1 if n is prime, 0 if not
 */
int is_prime(int n)
{
    int i;

    if (n == 2)
        return 1;
    if (n % 2 == 0 || n == 1)
        return 0;

    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}
