#include "monty.h"

/**
 * malloc_error - this function prints an error message to standard error
 */
void malloc_error(void)
{
	char output = "Error: malloc failed";

	if (write(2, output, strlen(output)) < 0)
		perror("write failure");
}
