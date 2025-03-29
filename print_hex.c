#include "main.h"
#include <unistd.h>

/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @n: The number to print.
 * @uppercase: If 1, prints uppercase letters (A-F), otherwise lowercase (a-f).
 *
 * Return: Number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
	char buffer[20];
	int i = 0, count = 0;
	char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
