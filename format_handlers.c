#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * print_char - Imprime un solo carácter.
 * @c: El carácter a imprimir.
 *
 * Return: Número de caracteres impresos (siempre 1).
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Imprime una cadena.
 * @s: La cadena a imprimir.
 *
 * Return: Número de caracteres impresos.
 */
int print_string(char *s)
{
	int count = 0;

	if (!s)
		s = "(null)";
	while (*s)
		count += write(1, s++, 1);

	return (count);
}

/**
 * print_int - Imprime un número entero.
 * @n: El número a imprimir.
 *
 * Return: Número de caracteres impresos.
 */
int print_int(int n)
{
	char buffer[12];
	int count = 0;

	convert_int(buffer, n);
	count = write(1, buffer, strlen(buffer));

	return (count);
}
