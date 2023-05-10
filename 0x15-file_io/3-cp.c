#include "main.h"

/**
 * args_checker - checks if the command line arguments are valid
 * @argc: argument counter
 * Return: none
 */
void args_checker(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * copy_file - copies the content of one file to another
 * @file_from: file descriptor of the source file
 * @file_to: file descriptor of the destination file
 * @argv: argument vector
 * Return: none
 */
void copy_file(int file_from, int file_to, char **argv)
{
	ssize_t bytes_read, bytes_written;
	char buff[1024];

	while ((bytes_read = read(file_from, buff, 1024)) > 0)
	{
		bytes_written = write(file_to, buff, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
}

/**
 * close_files - closes the file descriptor
 * @file_from: file descriptor of the source file
 * @file_to: file descriptor of the destination file
 * Return: none
 */
void close_files(int file_from, int file_to)
{
	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument counter
 * @argv: argument vector
 * Return: integer
 */
int main(int argc, char **argv)
{
	int file_from, file_to;

	args_checker(argc);
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	copy_file(file_from, file_to, argv);
	close_files(file_from, file_to);
	return (0);
}
