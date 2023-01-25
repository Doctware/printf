#include "main.h"

/**
 * _printf - it print output according toa format
 * @format: the string containing the character and the specifiers
 * Description: this function will call get_print() function that will
 * determine what printing function to call base i=on the conversion
 * specifiers contained into format
 * Return: lenght of the formatted output string
*/

int _printf(const char *format, ...)
{
	int (*sfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flag = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
	return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			sfunc = get_print(*p);
			count += (sfunc)
				? sfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments)
	return (count);
}
