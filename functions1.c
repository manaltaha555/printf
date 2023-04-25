#include"main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flag: find out flag
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	int i = BUFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsignd(0, i, buffer, flag, w, pre, size));
}
/**
 * print_octal - Prints an unsigned number in octal
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flag: find out flags
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flag & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsignd(0, i, buffer, flag, w, pre, size));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flag: Calculates active flags
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	return (print_hexa(type, "0123456789abcdef", buffer, flag, 'x', w, pre, size));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @type: arguments
 * @buffer:  array to handle printf process
 * @flag:  find out flags
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flag, 'X', w, pre, size));
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @type: Lista of arguments
 * @map: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: find  active flags
 * @w: get width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list type, char map[], char buffer[], int flag, char flag_ch, int w, int pre, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);
	num = convert_size_unsignd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, flag, w, pre, size));
}

