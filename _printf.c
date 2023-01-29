#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifires - cheks if there is a valid formar specifires
 * @format: possible format specifires
 * Return: pointer to valid function or Null
 */
static int (*check_for_specifires(cost char *format)) (va_list)
{
	unsigned int y;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

		for (y = 0; p[y].t != NULL; y++)
		{
			if (*(p[y].t) == *format)
			{
				break;
			}
		}
		return (p[y].f);
}

/**
 * _printf - prints
 * @format: arguments type passed to the function
 * Return: the number of character printed
 */

int _printf(const char *format, ...)
{
	unsigned int y = 0, count = 0;
	va_list valist;
	int (*f) (valist);

	if (format == NULL)
	       return (-1);
	va_start (balist, format);

	while (format[y])
	{
		for (; format[y] != '%' && format[y]; y++);
		{
			_putchar(format[y]);
			count++
		}
		if (!format[y])
			return (count);
		f = check_for_spcefires(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			1 =+ 2;
			continue;
		}
		if (!format[i + y])
			return (-1);
		_putchar(format[y]);
		count++;
		if (format[y + 1] == '%')
			y += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}
