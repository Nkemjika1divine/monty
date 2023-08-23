#include "monty.h"

stack_t *top = NULL;

/**
 * push - this function oushes an element onto a stack
 * @n: the element to be added
 */
void push(int n)
{
	stack_t *temp = malloc(sizeof(stack_t));

	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
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
			top->prev = temp;

			top = temp;
		}
	}
}


/**
 * pop - this function removes thetop element on the stack
 *
 * Return: 1 if successful and -1 if not
 */
int pop(void)
{
	stack_t *temp = top;

	if (top == NULL)
		return (-1);

	top = top->next;
	if (top != NULL)
		top->prev = NULL;
	free(temp);

	return (1);
}


/**
 * pall - prints all the content of the stack
 */
void pall(void)
{
	stack_t *temp = top;

	if (top != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}


/**
 * pint - prints the integer on top of the stack
 *
 * Return: 1 if successful and -1 if not
 */
int pint(void)
{
	if (top == NULL)
		return (-1);

	printf("%d\n", top->n);
	return (1);
}


/**
 * swap - swaps the top 2 elements of a stack
 *
 * Return: 1 if successful and -1 if not
 */
int swap(void)
{
	stack_t *first = top, *second = top->next;
	int a = top->n;

	if (top == NULL || top->next == NULL)
		return (-1);

	first->n = second->n;
	second->n = a;
	return (1);
}
