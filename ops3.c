#include "monty.h"

/**
 * mod - this function returns the remainder of the division of 2nd
 * by top and syroes in 2nd
 *
 * Return: 1 if successful, 0 if top is 0 and -1 if unsuccessful
 */
int mod(void)
{
	stack_t *first = top, *second = top->next;
	int a = 0;

	if (top == NULL || top->next == NULL)
		return (-1);

	if (first->n == 0)
		return (0);

	a = second->n % first->n;

	first->next = NULL;
	second->prev = NULL;

	second->n = a;
	top = second;
	free(first);
	return (1);
}
