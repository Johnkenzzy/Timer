#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void print_number(int n);

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *p;
	Buffur buf;

	va_start(args, format);
	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '\0')
				break;

			switch (*p)
			{
				case 'X':
					{
						int X = va_arg(args, int);
						print_upperhexadecimal(X);
						count++;
						break;
					}

				case 'c':
					{
						char c = (char) va_arg(args, int);
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char *);
						if (s == NULL) s = "(null)";
						while (*s)
						{
							putchar(*s++);
							count++;
						}
						break;
					}
				case '%': {
						  putchar('%');
						  count++;
						  break;
					  }
				default:
					  {
						  putchar('%');
						  putchar(*p);
						  count += 2;
						  break;
					  }
			}
		}
		else
		{
			putchar(*p);
			count++;
		}
	}
	va_end(args);
	return count;
}

void print_number(int n) {
    if (n == 0) {
        putchar('0');
        return;
    }

    if (n == -2147483648) {
        // Handle the special case for the smallest 32-bit signed integer
        putchar('-');
        putchar('2');
        n = 147483648;
    }

    if (n < 0) {
        putchar('-');
        n = -n;
    }

    int digits[10];
    int i = 0;

    // Extract digits and store them in the array
    while (n > 0) {
        digits[i] = n % 10;
        n /= 10;
        i++;
    }

    // Print digits in reverse order
    while (i > 0) {
        i--;
        putchar('0' + digits[i]);
    }
}
