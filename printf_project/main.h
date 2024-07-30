#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

/**
 * struct Buffer - A structure to manage a local buffer for efficient writing.
 * @buffer: An array of characters to hold the data before writing.
 * @index: An integer to track the current position in the buffer.
 *
 * This structure is used to accumulate output in a local buffer
 * and write it to the standard output in larger chunks to minimize
 * the number of write system calls.
 */
typedef struct
{
        char buffer[BUFFER_SIZE];
        int index;
} Buffer;


int _printf(const char *format, ...);
void print_unsigned(unsigned int n);
void print_octal(unsigned int n);
void print_lowerhexadecimal(unsigned int n);
void print_upperhexadecimal(unsigned int n);
void buffer_add_string(Buffer *buf, const char *str);
void print_string_custom(const char *str);
void print_string_custom(const char *str);

#endif /* MAIN_H */
