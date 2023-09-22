#include "sort.h"

/**
 * _puts - prints a string to stdout
 * @s: the string pointer
 */
void _puts(char *s)
{

	if (s == NULL)
		return;
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}
}
