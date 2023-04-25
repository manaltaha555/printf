#include"main.h"
/**
 *print_buffer - print the contents
 *@buffer: array
 *@buffer_index: index
 *Return: void
 *
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}
/**
 *_printf - simulation of printf function
 *@format: the input to the function
 *Return: number of printed characters
 *
 */
int _printf(const char *format, ...)
{
	int j, p = 0, p_chars = 0;
	int flag, width, precision, size, buffer_index = 0;

	va_list l;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(l, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buffer_index++] = format[j];
			print_buffer(buffer, &buffer_index);
			p_chars += 1;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flag = get_flag(format, &j);
			width = get_width(format, &j, l);
			precision = get_precision(format, &j, l);
			size = get_size(format, &j);
			j++;
			p = handle_print(format, &j, l, buffer, flag, width, precision, size);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}
	 print_buffer(buffer, &buffer_index);
	 va_end(l);
	 return (p_chars);
}
