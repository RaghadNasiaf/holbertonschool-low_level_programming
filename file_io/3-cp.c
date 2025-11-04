#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * close_fd - closes a file descriptor safely
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	int c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_src - open source file or exit(98)
 * @file_from: source path
 * Return: fd of source
 */
int open_src(const char *file_from)
{
	int fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	return (fd_from);
}

/**
 * open_dst - open destination file or exit(99)
 * @file_to: destination path
 * Return: fd of destination
 */
int open_dst(const char *file_to)
{
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	return (fd_to);
}

/**
 * copy_file - copies the content of one file to another
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r, w;
	char buf[BUF_SIZE];

	fd_from = open_src(file_from);

	/* probe read first to guarantee read-failure returns 98 before opening dst */
	r = read(fd_from, buf, BUF_SIZE);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close_fd(fd_from);
		exit(98);
	}

	fd_to = open_dst(file_to);

	while (r > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(99);
		}

		r = read(fd_from, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
			close_fd(fd_from);
			close_fd(fd_to);
			exit(98);
		}
	}

	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	return (0);
}

