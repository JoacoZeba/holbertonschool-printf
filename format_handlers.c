#include "main.h"

/**
 * print_char - Prints a single character.
 * @c: The character to print.
 *
 * Return: Number of characters printed (always 1).
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @s: The string to print.
 *
 * Return: Number of characters printed.
 */
int print_string(char *s)
{
	int count = 0;

	if (!s) 
		return (NULL);

	while (*s)
		count += write(1, s++, 1);

	return (count);
}

/**
 * print_int - Prints an integer.
 * @n: The integer to print.
 *
 * Return: Number of characters printed.
 */
int print_int(int n)
{
	char buffer[12];
	int count = 0;
	int i;

	convert_int (buffer, n);
	for (i = 0; buffer[i]; i++)
	{
		count += write(1, &buffer[i], 1);
	}
	return (count);
}
