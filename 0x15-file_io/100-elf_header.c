#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * elf_checker - checks if file is an elf file
 * @e_ident: a pointer to magic number
 * Return: 1 if elf, else 0
 */
void elf_checker(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 ||
			e_ident[i] != 'E' ||
			e_ident[i] != 'L' ||
			e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: file is not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * _magic - prints the magic number of the ELF file
 * @e_ident: a pointer to the header of the ELF file
 * Return: nothing
 */
void _magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

/**
 * _class - prints the class of the ELF file
 * @e_ident: a pointer to the header of the ELF file
 * Return: nothing
 */
void _class(unsigned char *e_ident)
{
		printf("  Class:                            ");
		switch (e_ident[EI_CLASS])
		{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_NIDENT]);
			break;
		}
}

/**
 * _data - prints the data encoding in the ELf file
 * @e_ident: a pointer to the header of the ELF file
 * Return: nothing
 */
void _data(unsigned char *e_ident)
{
	printf("  Data:                            ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, bid endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * _version - prints the version of the ELF file format
 * @e_ident: a pointer to the header of the ELF file
 * Return: void
 */
void _version(unsigned char *e_ident)
{
	printf("  Version:                            ");
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		default:
			printf("\n");
			break;
	}
}
/**
 * os_abi - prints the OS/ABI of the ELF file
 * @e_ident: a pointer to the header of the ELF file
 * Return: void
 */
void os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - Sysyem V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM architecture\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * _abi - prints the ABI Version of the Elf file
 * @e_indent - a pointer to the header of the ELF file
 * Return: void
 */
void _abi(unsigned char *e_ident)
{
	printf("  ABI Version:                           %x\n ",
		     e_ident[EI_ABIVERSION]);
}
/**
 * _type - prints the type of the ELF file
 * @e_type: a pointer to the header of an ELF file
 * @e_ident: a pointer
 * Return: void
 */
void _type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}
	printf("  Type:                            ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (An unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file");
			break;
		case ET_EXEC:
			printf("(Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<Unknown: %x>\n", e_type);
			break;
	}
}
/**
 * _address - prints the entry point address
 * @e_entry:  a pointer to the header of the ELF file
 * @e_ident: a pointer
 * Return: void
 */
void _address(unsigned int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:                            ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else if (e_ident[EI_DATA == ELFDATA2MSB])
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = ((e_entry << 16) | e_entry >> 16);
	}
	else
	{
		printf("%#x\n", e_entry);
	}
}

/**
 * main - displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *elf_header;
	int fd, read_elf;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not open file\n");
		exit(98);
	}
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		dprintf(STDERR_FILENO, "can't allocate memory\n");
		exit(98);
	}
	read_elf = read(fd, elf_header, sizeof(Elf64_Ehdr));
	if (read_elf == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not read ELF header\n");
		exit(98);
	}
	elf_checker(elf_header->e_ident);
	printf("ELF Header:\n");
	 _magic(elf_header->e_ident);
	_class(elf_header->e_ident);
	_data(elf_header->e_ident);
	_version(elf_header->e_ident);
	os_abi(elf_header->e_ident);
	_abi(elf_header->e_ident);
	_type(elf_header->e_type, elf_header->e_ident);
	_address(elf_header->e_type, elf_header->e_ident);
	free(elf_header);
	close(fd);
	return (0);
}
