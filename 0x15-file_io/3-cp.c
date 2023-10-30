#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_and_exit(char *str, char *filename, int exit_code)
{
    dprintf(STDERR_FILENO, "%s %s\n", str, filename);
    exit(exit_code);
}

int main(int argc, char *argv[])
{
    int file_from, file_to;
    char buf[BUF_SIZE];
    ssize_t n_read, n_written;

    if (argc != 3)
        error_and_exit("Usage: cp file_from file_to", "", 97);

    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
        error_and_exit("Error: Can't read from file", argv[1], 98);

    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1)
    {
        close(file_from);
        error_and_exit("Error: Can't write to", argv[2], 99);
    }

    while ((n_read = read(file_from, buf, BUF_SIZE)) > 0)
    {
        n_written = write(file_to, buf, n_read);
        if (n_written != n_read)
        {
            close(file_from);
            close(file_to);
            error_and_exit("Error: Can't write to", argv[2], 99);
        }
    }

    if (n_read == -1)
    {
        close(file_from);
        close(file_to);
        error_and_exit("Error: Can't read from file", argv[1], 98);
    }

    if (close(file_from) == -1)
        error_and_exit("Error: Can't close fd", argv[1], 100);
    
    if (close(file_to) == -1)
        error_and_exit("Error: Can't close fd", argv[2], 100);

    return (0);
}