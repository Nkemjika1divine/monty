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



/**
 * pchar - this function orints the ascii valie of the top element
 *
 * Return: 1 if successful, 0 if element cant be cobverted ,-1 if stack emoty
 */
int pchar(int count)
{
	if (top == NULL)
		return (-1);

	if (putchar(top->n) == EOF)
	{
		fprintf(stderr, "L%d, can't pchar, value out of range", count);
		exit(EXIT_FAILURE);
	}
	putchar('\n');

	return (1);
}



/**
 * pstr - prints te elements as their ascii vakues
 */
void pstr(void)
{
	stack_t *temp = top;

	if (top != NULL)
	{
		while (temp != NULL)
		{
			if (temp->n == 0)
				break;
			if (putchar(temp->n) == EOF)
				break;
			temp = temp->next;
		}
	}
	else
		putchar('\n');
}
