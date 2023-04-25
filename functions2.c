#include"main.h"
/**
 * print_pointer - Prints the value of a pointer
 * @type: arguments
 * @buffer:  array to handle printf process
 * @flag:  find out flags
 * @width: find out width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of characterss printed
 * */

int print_pointer(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	char extra_c = 0, pad = ' ';

	int index = BUFF_SIZE - 2, length = 2, pad_start = 1; 

        unsigned long num_add;

        char map[] = "0123456789abcdef";

        void *add = va_arg(type, void *);


        UNUSED(w);

        UNUSED(size);
	if (add == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

        UNUSED(pre);

	num_add= (unsigned long)add;
	while (num_add > 0)
	{
		buffer[index--] = map[num_add % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;
	index++;
	return (write_pointer(buffer, ind, length, w, flag, pad, extra_c, pad_start));
}
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @type: arguments
 * @buffer: handling printf process
 * @flag: find out flags
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	int i = 0, off= 0;
	char *str = va_arg(type, char *);
	
	UNUSED(flag);

        UNUSED(w);

        UNUSED(pre);

        UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		buffer[i + off] = str[i];
		else
			off += append_hexa_code(str[i], buffer, i + off);
		i++;
	}
	buffer[i + off] = '\0';
	return (write(1, buffer, i + off));
}
/**
 * print_reverse - Prints reverse string
 * @type: arguments
 * @buffer:  handing printf process
 * @flag: find out flag
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Numbers of characters printed
 */
int print_reverse(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);

        UNUSED(flag);

        UNUSED(w);

        UNUSED(size);


        str = va_arg(type, char *);
	if (str == NULL)
	{
		UNUSED(pre);
		str = "(Null)"
	}
	while (str[i])
		i++;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
       	return (count);
}
/**
 * print_rot13string - Print a string in rot13string
 * @type: arguments
 * @buffer: handling printf process
 * @flag: find flags
 * @w: find width
 * @pre: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list type, char buffer[], int flag, int w, int pre, int size)
{
	char x;
 	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	str = va_arg(type, char *);

	UNUSED(buffer);

        UNUSED(flag);

        UNUSED(w);

        UNUSED(pre);

        UNUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
