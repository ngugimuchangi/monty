#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
extern int num;

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

void pushstack(stack_t **structstack, unsigned int lineno);
void pallstack(stack_t **structstack, unsigned int lineno);
void peekstack(stack_t **structstack, unsigned int lineno);
void comS(stack_t **structstack, unsigned int lineno);


void dellineno(char **buf);
void tokenizer(char **buf, char ***tokens);
void instructchoose(stack_t **structstack, char ***tokens, unsigned int lineno);
void checknumber(char *n, unsigned int lineno);
void (*choose_operand(char *code))(stack_t **structstack, unsigned int lineno);
void monty_inter(char **av);
void freetokens(char ***tokens);
void free_structstack(stack_t *structstack);
void line_token(char **buf, char ***tokens, ssize_t readline);

#endif /* MONTY_H */
