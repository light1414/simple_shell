#include "main.h"

/**
 * get_sigint - can handle the crtl + c call in prompt
 * @sig: The signal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
