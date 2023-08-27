#include <stdio.h>
#include <stdlib.h>

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int len1 = 0, len2 = 0, total_len, i, j;
    char *concat;

    if (s1 == NULL)
        s1 = "";

    if (s2 == NULL)
        s2 = "";

    while (s1[len1] != '\0')
        len1++;

    while (s2[len2] != '\0')
        len2++;

    if (n >= len2)
        n = len2;

    total_len = len1 + n;

    concat = malloc(sizeof(char) * (total_len + 1));

    if (concat == NULL)
        return NULL;

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];

    for (j = 0; j < n; j++, i++)
        concat[i] = s2[j];

    concat[i] = '\0';

    return concat;
}
