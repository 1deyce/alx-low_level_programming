#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int append_text_to_file(const char *filename, char *text_content) {
    int fd;
    ssize_t n_written;
    size_t len = 0;

    if (filename == NULL)
        return (-1);

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return (-1);

    if (text_content != NULL) {
        while (text_content[len])
            len++;

        n_written = write(fd, text_content, len);
        if (n_written == -1 || n_written != len) {
            close(fd);
            return (-1);
        }
    }

    close(fd);

    return (1);
}