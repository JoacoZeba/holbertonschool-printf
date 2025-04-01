#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int handle_format(const char *format, va_list args);
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_int(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_pointer(void *ptr);
void convert_int(char *buffer, int n);
#endif /* MAIN_H */

