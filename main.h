#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stdio.h>
#include <unistd.h>
int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *s);
int print_int(int n);
void convert_int(char *buffer, int num);
int _putchar(char);
#endif /* MAIN_H */
