#include "main.h"

/**
 * main - copies the content of a file to another file
 * @argc: argument counter
 * @argv: argument vector
 * Return: integer
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, file_close;
	char buff[1024];
	ssize_t read_letts, write_letts;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	read_letts = read(file_from, buff, 1024);
	if (read_letts == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	while (read_letts > 0)
	{
		write_letts = write(file_to, buff, read_letts);
		if (write_letts != read_letts)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	file_close = close(file_from);
	if (file_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	file_close = close(file_to);
	if (file_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
