#include"main.h"
/**
 *print_char - prints  character
 *@t: arguments
 *@buffer: to handle the printf process
 *@flag: find flags
 *@w: width of the string
 *@pre: precision specification
 *@size: size of specifier
 *Return: number of characters
 *
 */
int print_char(va_list t, char buffer[], int flag, int w, int pre, int size)
{
	char c = va_arg(t, int);

	return (handle_write_char(c, buffer, flag, w, pre, size));
}
/**
 *print_string - prints the string
 *@t: arguments
 *@buffer: to handle the printf process
 *@flag: find flags
 *@w: find width
 *@pre: precision
 *@size: size of specifier
 *Return: number of characters
 */
int print_string(va_list t, char buffer[], int flag, int w, int pre, int size)
{
	int length = 0, i;
	char *str = va_arg(t, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (pre >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (pre >= 0 && pre < length)
		length = pre;
	if (w > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (w);
		}
	}
	return (write(1, str, length));
}
/**
 *print_binary - prints an unsigned number
 *@t: arguments
 *@buffer: to handelling printf process
 *@flag: find flags
 *@w: find width
 *@pre: precision
 *@size: size of specifiers
 *Return: number of characters
 *
 */
int print_binary(va_list t, char buffer[], int flag, int w, int pre, int size)
{
	unsigned int n, m, j, sum = 0;
	unsigned int a[32];
	int count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(pre);
	UNUSED(size);

	n = va_arg(t, unsigned int);
	m = 2147483648;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (n / m);
	}
	for (j = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char y = '0' + a[j];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
