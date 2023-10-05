#include "main.h"
#include <string.h>
#include <stdlib.h>

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    size_t len1 = strlen(s1);

    if (s1 == NULL) {
        s1 = "";
    }
    if (s2 == NULL) {
        s2 = "";
    }

    char *concat;
    concat = malloc(len1 + n + 1);
    if (concat == NULL) {
        return NULL;
    }

    strcpy(concat, s1);
    strncpy(concat + len1, s2, n);
    concat[len1 + n] = '\0';

    return concat;
}
