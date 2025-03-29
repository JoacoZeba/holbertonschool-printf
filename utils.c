#include "main.h"

/**
 * convert_int - Converts an integer to a string.
 * @buffer: Buffer to store the result.
 * @num: Integer to convert.
 */
void convert_int(char *buffer, int num)
{
	int i = 0, temp, is_negative = 0;
	int j, k;

	if (num == 0)
	{
		buffer[i++] = '0';
		buffer[i] = '\0';
		return;
	}

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num > 0)
	{
		temp = num % 10;
		buffer[i++] = temp + '0';
		num /= 10;
	}

	if (is_negative)
		buffer[i++] = '-';
	buffer[i] = '\0';

	/* Reverse the string */
	j = 0;
	k = i - 1;
	while (j < k)
	{
		char tmp = buffer[j];
		buffer[j] = buffer[k];
		buffer[k] = tmp;
		j++;
		k--;
	}
}
