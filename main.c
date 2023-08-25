#include "monty.h"


/**
 * global - holds the global variable
 */
void global(void);
stack_t *top = NULL;

/**
 * main - executes the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success and EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	char line[20], *tokens[5], *vec;
	int count = 0, a, i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r"); /*opening the monty bytecode file*/
	if (fd == NULL) /*file failed to open*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fd) != NULL)
	{
		if (spaces(line) != 1)
		{
			count++;
			line[strcspn(line, "\n")] = '\0'; /*null terminate the line*/
			vec = strtok(line, " "); /*tokenize the line*/
			if (vec[0] == '#') /*if the first character is a #*/
				continue;
			i = 0;
			while (vec != NULL)
			{
				tokens[i++] = _strdup(vec);
				vec = strtok(NULL, " ");
			}
			format_line1(tokens, count);
			for (a = 0; a < i; a++)
				free(tokens[a]);
		}
	}
	free_stack(top);
	fclose(fd);
	return (0);
}



/**
 * format_line1 - this checks the tokens for the functions to call
 * @tokens: the array of tokens
 * @count: the line number
 */
void format_line1(char *tokens[], int count)
{
	int a;

	if (strcmp(tokens[0], "push") == 0)
	{
		a = atoi(tokens[1]);
		if (strcmp(tokens[1], "0") == 0)
			push(0);
		else if (a == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
		else
			push(a);
	}
	else if (strcmp(tokens[0], "pop") == 0)
	{
		if (pop() == -1)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "pint") == 0)
	{
		if (pint() == -1)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "swap") == 0)
	{
		if (swap() == -1)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
		format_line2(tokens, count);
}



/**
 * format_line2 - continues executing commands according to lines read
 * @tokens: the array of tokens
 * @count: the line number
 */
void format_line2(char *tokens[], int count)
{
	if (strcmp(tokens[0], "add") == 0)
	{
		if (add() == -1)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "sub") == 0)
	{
		if (sub() == -1)
		{
			fprintf(stderr, "L%d: can't sub, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "mul") == 0)
	{
		if (mul() == -1)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "div") == 0)
	{
		if (divi() == -1)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
		else if (divi() == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else
		format_line3(tokens, count);
}



/**
 * format_line3 - continues executing functions based on lines read
 * @tokens: the array of tokens
 * @count: line number
 */
void format_line3(char *tokens[], int count)
{
	if (strcmp(tokens[0], "mod") == 0)
	{
		if (mod() == -1)
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", count);
			exit(EXIT_FAILURE);
		}
		else if (mod() == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "nop") == 0)
		nop();
	else if (strcmp(tokens[0], "pall") == 0)
		pall();
	else if (strcmp(tokens[0], "pchar") == 0)
	{
		if (pchar(count) == -1)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(tokens[0], "pstr") == 0)
		pstr();
	else if (strcmp(tokens[0], "rotr") == 0)
		rotr();
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, tokens[0]);
		exit(EXIT_FAILURE);
	}
}





/**
 * free_stack - frees the stack_t
 * @top: pointer to the first node
 */
void free_stack(stack_t *top)
{
	stack_t *temp = top;

	while (temp != NULL)
	{
		temp = temp->next;
		free(top);
		top = temp;
	}
}
