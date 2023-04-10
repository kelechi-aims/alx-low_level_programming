#include "main.h"

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: name of the file
 * @text_content: is NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_con, con_letts = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND, 0664);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}
	if (text_content != NULL)
	{
		while (text_content[con_letts] != '\0')
		{
			con_letts++;
		}
	}
	write_con = write(fd, text_content, con_letts);
	if (write_con == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
