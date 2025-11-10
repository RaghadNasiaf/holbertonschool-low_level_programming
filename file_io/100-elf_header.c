#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(98);
}

void print_header(Elf64_Ehdr *h)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", h->e_ident[i]);
    printf("\n");

    printf("  Class:                             %s\n",
        h->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
        h->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Unknown");

    printf("  Data:                              %s\n",
        h->e_ident[EI_DATA] == ELFDATA2LSB ?
        "2's complement, little endian" :
        h->e_ident[EI_DATA] == ELFDATA2MSB ?
        "2's complement, big endian" : "Unknown");

    printf("  Version:                           %d (current)\n",
        h->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (h->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
    case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
    default: printf("Unknown\n"); break;
    }

    printf("  ABI Version:                       %d\n", h->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (h->e_type)
    {
    case ET_EXEC: printf("EXEC (Executable file)\n"); break;
    case ET_DYN: printf("DYN (Shared object file)\n"); break;
    case ET_REL: printf("REL (Relocatable file)\n"); break;
    default: printf("Unknown type\n"); break;
    }

    printf("  Entry point address:               0x%lx\n",
        (unsigned long)h->e_entry);
}

int main(int ac, char **av)
{
    int fd;
    Elf64_Ehdr h;

    if (ac != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Can't read file");

    if (read(fd, &h, sizeof(h)) != sizeof(h))
        print_error("Error: Can't read ELF header");

    if (h.e_ident[EI_MAG0] != ELFMAG0 ||
        h.e_ident[EI_MAG1] != ELFMAG1 ||
        h.e_ident[EI_MAG2] != ELFMAG2 ||
        h.e_ident[EI_MAG3] != ELFMAG3)
        print_error("Error: Not an ELF file");

    print_header(&h);
    close(fd);
    return (0);
}
