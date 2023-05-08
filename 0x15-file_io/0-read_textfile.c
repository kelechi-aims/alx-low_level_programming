#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file to be open
 * @letters: the number of letters it should read and print
 * Return: the actual numbers of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_letts, write_letts;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * (letters));
	if (buff == NULL)
	{
		return (0);
	}
	read_letts = read(fd, buff, letters);
	if (read_letts == -1)
	{
		free(buff);
		return (0);
	}
	write_letts = write(STDOUT_FILENO, buff, read_letts);
	if (write_letts == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}
	close(fd);
	return (write_letts);
}
