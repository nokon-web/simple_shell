#include "shell.h"

/**
 *puts_e - prints an input
 *@word: the string to be printed
 *
 * Return: Nothing
 */
void puts_e(char *word)
{
	int i = 0;

	if (!word)
		return;
	while (word[i] != '\0')
	{
		putchar_e(word[i]);
		i++;
	}
}

/**
 * putchar_e - writes the character c to stderr
 * @letter: The character to print
 *
 * Return: On sucess 1.
 * On error, -1 is returned, and errno is set appropraitely.
 */
int putchar_e(char letter)
{
	static int idx;
	static char buf[WRITE_BUF_SIZE];

	if (letter == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(2, buf, idx);
		idx = 0;
	}
	if (letter != BUF_FLUSH)
		buf[idx++] = letter;
	return (1);
}

/**
 * put_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropraitely.
 */
int put_fd(char c, int fd)
{
	static int idx;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || idx >= WRITE_BUF_SIZE)
	{
		write(fd, buf, idx);
		idx = 0;
	}
	if (c != BUF_FLUSH)
		buf[idx++] = c;
	return (1);
}
/**
 * puts_fd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars to put
 */
int puts_fd(char *str, int fd)
{
	int idx = 0;

	if (!str)
		return (0);
	while (*str)
	{
		idx += put_fd(*str++, fd);
	}
	return (idx);
}

