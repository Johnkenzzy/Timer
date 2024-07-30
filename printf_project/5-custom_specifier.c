#include <main.h>

/**
 * print_string_custom - Prints a string, replacing non-printable characters.
 * @str: The string to print.
 *
 * Non-printable characters are printed as \x followed by the ASCII code
 * value in uppercase hexadecimal.
 */
void print_string_custom(const char *str)
{
	while (*str)
	{
		if (*str > 0 && (*str < 32 || *str >= 127))
		{
			buffer_add_char('\\');
			buffer_add_char('x');
			print_upperhexadecimal((unsigned int)*str);
		}
		else
		{
			buffer_add_char(*str);
		}
		str++;
	}
}
