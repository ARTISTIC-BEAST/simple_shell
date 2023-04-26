#include "shell.h"
/**
 * ctrap - captures ^C signal to avoid killing shell process
 * @signal: signal to capture
 */

void ctrap(int signal)
{
	(void)signal;
	write(STDOUT, "\n\033[96maw$: \033[0m", 15);
}
