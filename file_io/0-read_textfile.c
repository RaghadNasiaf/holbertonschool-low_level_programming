#include "main.h"

/**
 * read_into_buf - reads bytes from a file descriptor into a buffer
 * @fd: file descriptor to read from
 * @buf: buffer to fill with data
 * @n: number of bytes to read
 *
 * Return: number of bytes read, or -1 on failure.
 */
static ssize_t read_into_buf(int fd, char *buf, size_t n)
{
	ssize_t r;

	r = read(fd, buf, n);
	return (r);
}

/**
 * write_all_stdout - writes all bytes from a buffer to STDOUT
 * @buf: buffer containing data to write
 * @n: number of bytes to write
 *
 * Return: number of bytes written, or -1 on failure.
 */
static ssize_t write_all_stdout(const char *buf, size_t n)
{
	ssize_t total = 0, w;

	while (total < (ssize_t)n)
	{
		w = write(STDOUT_FILENO, buf + total, n - total);
		if (w == -1)
			return (-1);
		total += (ssize_t)w;
	}
	return ((ssize_t)total);
}

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to the file
 * @letters: number of bytes to read and print
 *
 * Return: actual number of bytes printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, printed;
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
