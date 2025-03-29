#include "main.h"
#include <unistd.h>

/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	char buffer[20];
	int i = 0, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i-- > 0)
		count += write(1, &buffer[i], 1);

	return (count);
}
