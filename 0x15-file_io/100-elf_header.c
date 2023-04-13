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
 * main - displays the information contained in the ELF header
 * at the start of an ELF file
 * @argc: argument counter
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd, read_elf;
	char buff[16];

	if(argc != 2)
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
	read_elf = read(fd, buff, 16);
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

}
