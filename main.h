#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_int(int n);
void convert_int(char *buffer, int num);
int print_unsigned(unsigned int n);
int _putchar(char);
int print_hex(unsigned int n, int uppercase);
int print_pointer(void *ptr);
int print_octal(unsigned int n);
#endif /* MAIN_H */
