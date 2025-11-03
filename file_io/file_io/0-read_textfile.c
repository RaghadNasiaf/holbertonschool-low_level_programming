#include "main.h"

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to the file
 * @letters: number of bytes to read and print
 *
 * Return: actual number of bytes printed, or 0 on any failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rbytes, wbytes, written = 0;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	rbytes = read(fd, buf, letters);
	if (rbytes == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	while (written < rbytes)
	{
		wbytes = write(STDOUT_FILENO, buf + written, rbytes - written);
		if (wbytes == -1)
		{
			free(buf);
			close(fd);
			return (0);
		}
		written += wbytes;
	}

	free(buf);

	if (close(fd) == -1)
		return (0);

	return (written);
}
