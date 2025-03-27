#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int handle_format(const char *format, va_list args);

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	count = handle_format(format, args);

	va_end(args);
	return (count);
}

int handle_format(const char *format, va_list args)
{
	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int temp = print_char(va_arg(args,  int));

				count = count + temp;
			}
			else if (*format == 's')
			{
				int temp = print_string(va_arg(args, char *));

				count = count + temp;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int temp = print_int(va_arg(args, int));

				count = count + temp;
			}
			else if (*format == 'u')
			{
				int temp = print_unsigned(va_arg(args, unsigned int));

				count = count + temp;
			}
			else if (*format == 'o')
			{
				int temp = print_octal(va_arg(args, unsigned int));

				count = count + temp;

			}
			else if (*format == 'x')
			{
				int temp = print_hex(va_arg(args, unsigned int), 0);

				count = count + temp;

			}
			else if (*format == 'X')
			{
				int temp = print_hex(va_arg(args, unsigned int), 1);

				count = count + temp;

			}
			else if (*format == 'p')
			{
				int temp = print_pointer(va_arg(args, void *));

				count = count + temp;

			}
			else if (*format == '%')
			{
				count = count + write(1, "%%", 1);
			}
			else
			{
				count = count + write(1, "%%", 1);
				count = count + write(1, format, 1);
			}
		}
		else
		{
			count = count + write(1, format, 1);
		}
		format++;
	}
	return (count);
}
