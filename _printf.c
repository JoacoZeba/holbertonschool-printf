#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Produces output according to a format.
 * @format: The format string containing directives.
 *
 * Description: This function mimics the standard printf function.
 * It processes the format string and calls the corresponding handlers
 * for each format specifier found.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
				count += print_char(va_arg(args, int));
			else if (*format == 's')
				count += print_string(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				count += print_int(va_arg(args, int));
			else if (*format == '%')
				count += write(1, "%%", 1);
			else
			{
				count += write(1, "%%", 1);
				count += write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (count);
}
