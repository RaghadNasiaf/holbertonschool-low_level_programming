#include "main.h"

/* reads up to n bytes from fd into buf */
static ssize_t read_into_buf(int fd, char *buf, size_t n)
{
	ssize_t r;

	r = read(fd, buf, n);
	return (r);
}

/* writes exactly n bytes from buf to STDOUT */
static ssize_t write_all_stdout(const char *buf, size_t n)
{
	size_t total = 0;
	ssize_t w;

	while (total < n)
	{
		w = write(STDOUT_FILENO, buf + total, n - total);
		if (w == -1)
			return (-1);
		total += (size_t)w;
	}
	return ((ssize_t)total);
}

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to file
 * @letters: number of bytes to read and print
 * Return: bytes printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t r, printed;

	if (!filename || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}

	r = read_into_buf(fd, buf, letters);
	if (r == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	printed = write_all_stdout(buf, (size_t)r);
	free(buf);

	if (close(fd) == -1 || printed == -1)
		return (0);

	return (printed);
}

