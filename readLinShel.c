#include "main.h"

/**
 * read_line - Reads input string.
 *
 * @i_eof: It returns the value of getline function
 * Return: the input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
