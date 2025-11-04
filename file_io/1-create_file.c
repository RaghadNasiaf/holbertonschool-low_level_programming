#include "main.h"

/**
 * create_file - creates a file and writes text into it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	/* compute length if text_content is not NULL */
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	/* create/truncate with rw------- (0600) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* write only if there is content (len>0). If NULL, write 0 bytes */
	w = write(fd, text_content, len);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
