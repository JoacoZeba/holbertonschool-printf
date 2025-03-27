#include "main.h"
#include <unistd.h>

/**
 * print_pointer - Prints a memory address.
 * @ptr: The pointer to print.
 *
 * Return: Number of characters printed.
 */
int print_pointer(void *ptr)
{
	unsigned long address = (unsigned long)ptr;
	int count = 0;

	count += write(1, "0x", 2);
	count += print_hex(address, 0);

	return (count);
}
