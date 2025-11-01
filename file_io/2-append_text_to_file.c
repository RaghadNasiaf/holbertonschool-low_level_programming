#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: path to the file
 * @text_content: NULL-terminated string to append
 *
 * Return: 1 on success, -1 on failure
 * Notes:
 * - Do not create the file if it does not exist.
 * - If text_content is NULL, do not add anything; return 1 if the file exists,
 *   otherwise -1 if the file does not exist or you cannot write to it.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w, len = 0;

	if (filename == NULL)
		return (-1);

	/* open for writing at end; do NOT create if missing */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		if (close(fd) == -1)
			return (-1);
		return (1);
	}

	while (text_content[len])
		len++;

	w = write(fd, text_content, len);
	if (w == -1 || w != len)
	{
		close(fd);
		return (-1);
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
