#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;


/*ops1.c*/
void push(int n);
int pop(void);
void pall(void);
int swap(void);
int pint(void);



/*ops2.c*/
int add(void);
void nop(void);
int sub(void);
int divi(void);
int mul(void);



/*ops3.c*/
int mod(void);


/*main.c*/
void format_line1(char *tokens[], int count);
void format_line2(char *tokens[], int count);
void format_line3(char *tokens[], int count);


/*utility.c*/
char *_strdup(char *str);
int is_space(char c);
int spaces(char *input);
char *remove_hash(char *line);

#endif
