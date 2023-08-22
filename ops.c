#include "monty.h"

/**
 * push - this function oushes an element onto a stack
 * @n: the element tk add
 */
void push(int n)
{
	instruction_t *temp = malloc(sizeof(instruction_t));

	if (temp == NULL)
		malloc_error();
	else
	{
		if (top == NULL)
		{
			temp->n = n;
			temp->prev = NULL;
			temp->next = NULL;
			top = temp;
		}
		else
		{
			temp->prev = NULL;
			temp->n = n;
			temp->next = top;
			top->next = temp;

			top = temp;
		}
	}
}
