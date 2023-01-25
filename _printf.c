#include "main.h"

/**
 * no_struct - a helper function ths is called when when there is a %stuff
 * @c: the character pass tha was after %
 * @count: the number of count so far. it will be increment
 * @argu: the va_list that is passed to be able to va_arg it
 *
 * Description: MY STRUCT IS DIFFRENT
 *Return: total of the count
*/

int no_struct(char c, int count, va_list argu)
{
	int h;
	char *s;

	switch (c)
	{
		case 'c':
			h = va_arg(argu, int);
			count += _putchar(h);
			break;
		case 's':
			s = va_arg(argu, char *);
			if (!s)
			{
				_putchar('(');
				_putchar('n');
				_putchar('u');
				_putchar('l');
				_putchar('l');
				_putchar(')');
			}
			else
				count += _putstring(s);
			break;
		case 'i':
		case 'd':
			h = va_arg(argu, int);
			if (!h)
			{
				count++;
				_putchar('0');
			}
			else
				count += print_number(h);
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'b':
			h = va_arg(argu, int);
			count += dec_to_binary(h);
			break;
		case 'r':
			s = va_arg(argu, char *);
			count += rev_str(s);
			break;
		case 'R':
			s = va_arg(argu, char *);
			count += rot13(s);
			break;
		default:
			count += 2;
			_putchar('%');
			_putchar('c');
	}
	return (count);
}
/**
 * _printf - it print output according toa format
 * @format: the string containing the character and the specifiers
 * Description: this function will call _putchar(c) function that will
 * determine what printing function to call base i=on the conversion
 * specifiers contained into format
 * Return: lenght of the formatted output string
 */

int _printf(const char *format, ...)
{
	int s = 0;
	int count = 0;
	va_list argu;

	va_start(argu, format);

	if (!format)
		return (-1);

	for (s = 0; format[s]; s++)
	{
		if (format[s] != '%')
		{
			count++;
			_putchar(format[s]);
		}
		else if (format[s + 1])
		{
			s++;
			count = no_struct(format[s], count, argu);
		}
		else
			return (-1);
	}
	va_end(argu);
	return (count);
}
