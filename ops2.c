#include "monty.h"

/**
 * add - adds tbe top 2 elements of the stack & uses it to replace the second
 *
 * Return: 1 if successful and 0 if not
 */
int add(void)
{
	stack_t *first = top;
	stack_t *second = top->next;
	int a = 0;

	if (top == NULL || top->next == NULL)
		return (-1);

	a = first->n + second->n;

	first->next = NULL;
	second->prev = NULL;

	second->n = a;
	top = second;
	return (1);
}


/**
 * nop - this function does nothing
 */
void nop(void)
{
	/*an empty function*/
}



/**
 * sub - finds the difference of the top 2 elements ,embeds it in the second
 *
 * Return: 1 if successful and -1 if not
 */
int sub(void)
{
	stack_t *first = top, *second = top->next;
	int a = 0;

	if (top == NULL || top->next == NULL)
		return (-1);

	a = first->n - second->n;

	first->next = NULL;
	second->prev = NULL;

	second->n = a;
	top = second;
	return (1);
}


/**
 * div - divides the too by the secind and reolaces the second with the reault
 *
 * Return: 1 f successful, 0 if top is 0 and -1 if not successful
 */
int div(void)
{
	stack_t *first = top, *second = top->next;
	int a = 0;

	if (top == NULL || top->next == NULL)
		return (-1);

	if (first->n == 0)
		return (0);

	a = second->n / first->n;

	first->next = NULL;
	second->prev = NULL;

	second->n = a;
	top = second;
	return (1);
}



/**
 * mul - multuplues the top 2 integers and places the product in the secind
 *
 * Return: 1 if successful and 0 if not
 */
int mul(void)
{
	stack_t *first = top, *second = top->next;
	int a = 0;

	if (top == NULL || top->next == NULL)
		return (-1);

	a = first->n * second->n;

	first->next = NULL;
	second->prev = NULL;

	second->n = a;
	top = second;
	return (1);
}
