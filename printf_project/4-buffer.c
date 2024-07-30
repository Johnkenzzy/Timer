#include <unistd.h>
#include <stdio.h>
#include "main.h"

typedef struct
{
	char buffer[BUFFER_SIZE];
	int index;
} Buffer;


/**
 * flush_buffer - Flushes the buffer to standard output.
 * @buf: Pointer to the buffer structure.
 *
 * Writes the contents of the buffer to the standard output
 * and resets the buffer index to 0.
 */void flush_buffer(Buffer *buf)
{
	if (buf->index > 0)
	{
		write(STDOUT_FILENO, buf->buffer, buf->index);
		buf->index = 0;
	}
}


/**
 * buffer_add_char - Adds a character to the buffer.
 * @buf: Pointer to the buffer structure.
 * @c: Character to add to the buffer.
 *
 * Adds a character to the buffer and flushes it if the buffer is full.
 */void buffer_add_char(Buffer *buf, char c)
{
	buf->buffer[buf->index++] = c;
	if (buf->index >= BUFFER_SIZE)
	{
		flush_buffer(buf);
	}
}


/**
 * buffer_add_string - Adds a string to the buffer.
 * @buf: Pointer to the buffer structure.
 * @str: String to add to the buffer.
 *
 * Adds a string to the buffer, character by character,
 * and flushes the buffer if necessary.
 */void buffer_add_string(Buffer *buf, const char *str)
{
	while (*str)
	{
		buffer_add_char(buf, *str++);
	}
}
