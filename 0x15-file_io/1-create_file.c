#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to be created
 * @text_content: text content for the created file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_con, con_letts = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 600);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content == NULL)
	{
		text_content = "";
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
