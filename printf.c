#include "main.h"

/**
 * _printf - Produces output arccording to input
 * @format: a Character string
 * Return: returns the number of charaacter printed
 * (exclude the Null byte used to end string)
 */

int _printf(const char *format, ...)
{

	va_list args;
	int count = 0;
	char c;
	char *str;

	va_start(args, format);

	while ((c = *format++) != '\0')
	{
		if (c == '%')
		{
			c = *format++;
			if (c == 'c')
			{
				_putchar(va_arg(args, int));
				count++;
			}
			else if (c == 's')
			{
				str = va_arg(args, char*);
				while (*str)
				{
					_putchar(*str++);
					count++;
				}
			}
			else if (c == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(c);
				count += 2;
			}
		}
		else
		{
			_putchar(c);
			count++;
		}
	}

	va_end(args);
	return (count);
}
