#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

void print_elf_header(Elf64_Ehdr *header) {
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int fd;
    Elf64_Ehdr header;
  
    if (argc != 2) {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        return 98;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 98;
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        perror("Error reading file");
        return 98;
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file\n");
        return 98;
    }

    print_elf_header(&header);

    close(fd);

    return 0;
}
