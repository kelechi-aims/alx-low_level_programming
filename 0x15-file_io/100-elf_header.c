#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * elf_checker - checks if file is an elf file
 * @ppt: a pointer to magic number
 * Return: 1 if elf, else 0
 */
int elf_checker(char *ppt)
{
	int ppt1 = (int)ppt[0];

	if (ppt1 == 127 && ppt[1] == 'E' && ppt[2] == 'L' && ppt[3] == 'F')
	{
		return (1);
	}
	return (0);
}

/**
 * _magic - prints the magic number of the ELF file
 * @ppt: a pointer to the header of the ELF file
 * Return: nothing
 */
void _magic(char *ppt)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x", ppt[i]);
	}
	printf("\n");
}

/**
 * _class - prints the class of the ELF file
 * @ppt: a pointer to the header of the ELF file
 * Return: nothing
 */
void _class(char *ppt)
{
	char cls = ppt[4] + '0';

	if (cls == '1')
	{
		printf("  Class:                             ELF32\n");
	}
	if (cls == '2')
	{
		printf("  Class:                             ELF64\n");
	}
}

/**
 * _data - prints the data encoding in the ELf file
 * :@ppt: a pointer to the header of the ELF file
 * Return: nothing
 */
void _data(char *ppt)
{
	char dt = ppt[5] + '0';

	if (dt == '1')
	{
		printf("  Data:                             2's complement, little edian\n");
	}
	if (dt == '2')
	{
		printf("  Data:                             2's complement, big edian\n");
	}
}

/**
 * _version - prints the version of the ELF file format
 * @ppt: a pointer to the header of the ELF file
 * Return: void
 */
void _version(char *ppt)
{
	char vrs = ppt[6] + '0';

	if (vrs == '1')
	{
		printf("  Version:                             %d (current)\n", vrs);
	}
}

/**
 * os_abi - prints the OS/ABI of the ELF file
 * @ppt: a pointer to the header of the ELF file
 * Return: void
 */
void os_abi(char *ppt)
{
	if (ppt[7] == 0)
	{
		printf("  OS/ABI:                             UNIX - Sysyem V\n");
	}
	else if (ppt[7] == 1)
	{
		printf("  OS/ABI:                             UNIX - HP-UX\n");
	}
	else if (ppt[7] == 2)
	{
		printf("  OS/ABI:                             UNIX - NetBSD\n");
	}
	else if (ppt[7] == 3)
	{
		printf("  OS/ABI:                             UNIX - Linux\n");
	}
	else if (ppt[7] == 6)
	{
		printf("  OS/ABI:                             UNIX - Solaris\n");
	}
	else if (ppt[7] == 8)
	{
		printf("  OS/ABI:                             UNIX -IRIX\n");
	}
	else if (ppt[7] == 9)
	{
		printf("  OS/ABI:                             UNIX - FreeBSD\n");
}
	else
	{
		printf("  OS/ABI:                             <unknown: %x>\n", ppt[7]);
	}
}

/**
 * _type - prints the type of the ELF file
 * @ppt: a pointer to the header of an ELF file
 * Return: void
 */
void _type(char *ppt)
{
	char tp = ppt[16];

	if (ppt[5] == 1)
	{
		tp = ppt[16];
	}
	else
	{
		tp = ppt[17];
	}
	if (tp == 0)
	{
		printf("  Type:                             NONE (No file type)\n");
	}
	else if (tp == 1)
	{
		printf("  Type:                             REL (Relocatable file)\n");
	}
	else if (tp == 2)
	{
		printf("  Type:                             EXEC (Executable file)\n");
	}
	else if (tp == 3)
	{
		printf("  Type:                             DYN (Shared file)\n");
	}
	else if (tp == 4)
	{
		printf("  Type:                             CORE (Core file)\n");
	}
	else
	{
		printf("  Type:                             <Unknown: %x>\n", tp);
	}
}

/**
 * _address - prints the entry point address
 * @ppt:  a pointer to the header of the ELF file
 * Return: void
 */
void _address(char *ppt)
{
	int i, strt;
	char cls = ppt[4] + '0';

	printf("  Entry point address:                             0x");
	if (cls == '1')
	{
		strt = 26;
		printf("80");
		for (i = strt; i >= 22; i--)
		{
			if (ppt[i] > 0)
				printf("%x", ppt[i]);
			else
				printf("%x", 256 + ppt[i]);
		}
		if (ppt[7] == 6)
			printf("00");
	}
	if (cls == '2')
	{
		strt = 26;
		for (i = strt; i > 23; i--)
		{
			if (ppt[i] >= 0)
				printf("%02x", ppt[i]);
			else
				printf("%02x", 256 + ppt[i]);
		}
	}
	printf("\n");
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
	int fd, read_elf;
	char buff[64];

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
	lseek(fd, 0, SEEK_SET);
	read_elf = read(fd, buff, 64);
	if (read_elf == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not read ELF header\n");
		exit(98);
	}
	if (!elf_checker(buff))
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		exit(98);
	}
	printf("ELF Header:\n");
	_magic(buff);
	_data(buff);
	_version(buff);
	os_abi(buff);
	printf("  ABI Version:                             %d\n", buff[8]);
	_type(buff);
	_address(buff);
	close(fd);
	return (0);
}
