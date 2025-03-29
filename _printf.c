#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * handle_format - Procesa el formato y llama a las funciones adecuadas.
 * @format: Cadena de formato.
 * @args: Lista de argumentos.
 *
 * Return: Número de caracteres impresos.
 */
int handle_format(const char *format, va_list args)
{
    int count = 0;

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
            else if (*format == 'u')
                count += print_unsigned(va_arg(args, unsigned int));
            else if (*format == 'o')
                count += print_octal(va_arg(args, unsigned int));
            else if (*format == 'x')
                count += print_hex(va_arg(args, unsigned int), 0);
            else if (*format == 'X')
                count += print_hex(va_arg(args, unsigned int), 1);
            else if (*format == 'p')
                count += print_pointer(va_arg(args, void *));
            else if (*format == '%')
                count += write(1, "%", 1);
            else
            {
                count += write(1, "%", 1);
                count += write(1, format, 1);
            }
        }
        else
            count += write(1, format, 1);
        format++;
    }
    return (count);
}

/**
 * _printf - Imprime salida según un formato.
 * @format: Cadena de formato.
 *
 * Return: Número de caracteres impresos.
 */
int _printf(const char *format, ...)
{
    int count;
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);
    count = handle_format(format, args);
    va_end(args);

    return (count);
}
