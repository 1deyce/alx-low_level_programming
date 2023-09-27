#include <stdio.h>
#include <string.h>

int is_palindrome(char *s)
{
    int len = strlen(s);
    int i;

    if (len <= 1)
        return 1;  /* Empty string or single character is a palindrome */

    for (i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1])
            return 0;  /* Characters don't match, not a palindrome */
    }

    return 1;  /* All characters match, it's a palindrome */
}
