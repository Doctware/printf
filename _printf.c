#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifires - cheks if there is a valid formar specifires
 * @format: possible format specifires
 * Return: pointer to valid function or Null
 */
static int (*check_for_specifires(cost char *format)) (va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
	}
}
