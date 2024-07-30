#include <stdio.h>

/***======HELPER FUNCTION======***/
/**
 * print_digits - prints digits
 * @n: argument
 * return: nothing
 */void print_digits(unsigned int n)
{
	if (n == 0)
		return;

	print_digits(n / 10);
	putchar((n % 10) + '0');
}

/***=====FORMAT SPECIFIERS FUNCTIONS======***/

/**
 * print_unsigned - prints unsigned integer
 * @arg: takes an unsigned integer as argument
 * return: nothing
 */void print_unsigned(unsigned int n)
{
	if (n == 0)
		return;
	else
		print_digits(n);
}


/**
 * print_octal - prints integer in octal format
 * @n: argument
 * return: nothing
 */void print_octal(unsigned int n)
{
	if (n / 8 != 0)
	{
		print_octal(n / 8);
	}
	putchar('0'+ (n % 8));
}

void print_lowerhexadecimal(unsigned int n)
{
	if (n / 16 != 0)
	{
		print_lowerhexadecimal(n / 16);
	}
	int leftover = n % 16;

	if (leftover < 10)
	{
		putchar('0' + leftover);
	}
	else
	{
		putchar('a' + (leftover - 10));
	}
}

void print_upperhexadecimal(unsigned int n)
{
	if (n / 16 != 0)
	{
		print_upperhexadecimal(n / 16);
	}
	int leftover = n % 16;

	if (leftover < 10)
	{
		putchar('0' + leftover);
	}
	else
	{
		putchar('A' + (leftover - 10));
	}
}
