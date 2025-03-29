#include "main.h"
#include <unistd.h>

/**
 * print_octal - Converts an unsigned integer to octal and prints it.
 * @n: The unsigned integer to convert and print.
 *
 * Return: Number of characters printed.
 */

int print_octal(unsigned int n)
{
	char buffer[20];
	int i = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}

	while (i-- > 0)
		count += write(1, &buffer[i], 1);

	return (count);
}
