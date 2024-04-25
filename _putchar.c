#include <unistd.h>

/**
 * _putchar - print to standard output
 * @c: character to be printed
 * Return: printed character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
