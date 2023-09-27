#include "main.h"

int is_prime_number(int n)
{
    int i;

    if (n <= 1) {
        return 0;  /* Numbers less than or equal to 1 are not prime */
    }

    /* Check for divisibility from 2 to the square root of n */
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;  /* n is divisible by i, hence not prime */
        }
    }

    return 1;  /* n is prime */
}
