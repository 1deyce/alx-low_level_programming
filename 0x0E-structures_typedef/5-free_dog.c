#include <stdlib.h>
#include "dog.h"

void free_dog(dog_t *d)
{
    if (d == NULL)
        return;

    /* Free the memory allocated for the name and owner strings */
    free(d->name);
    free(d->owner);

    /* Free the memory allocated for the dog structure */
    free(d);
}
