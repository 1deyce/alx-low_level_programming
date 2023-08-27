#include <stdio.h>
#include <stdlib.h>

void print_opcodes(unsigned char *start, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    int num_bytes = atoi(argv[1]);
    if (num_bytes < 0)
    {
        printf("Error\n");
        return 2;
    }

    unsigned char *main_ptr = (unsigned char *)main;

    print_opcodes(main_ptr, num_bytes);

    return 0;
}
