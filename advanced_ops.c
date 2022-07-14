#include "monty.h"

/**
 * pchar - prints the first number in a stack as ASCII character
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void pchar(stack_t **structstack, unsigned int lineno)
{
	stack_t *temp = *structstack;

	if (!temp)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 32)
		printf("%c\n", temp->n);
}

/**
 * pstr - prints all numbers in stack as ASCII characters
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void pstr(stack_t **structstack, unsigned int lineno)
{
	stack_t *temp = *structstack;
	(void) lineno;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		if (temp->n >= 32)
			printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - moves top stack element to to the bottom
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void rotl(stack_t **structstack, unsigned int lineno)
{
	stack_t *top = *structstack, *temp = *structstack;
	(void) lineno;

	while (temp)
	{
		if (!temp->next)
		{
			temp->next = top;
			top->prev = temp;
			*structstack = top->next;
			top->next = NULL;
			(*structstack)->prev = NULL;
			break;
		}
		temp = temp->next;
	}
}

/**
 * rotr - moves bottom stack element to the top
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void rotr(stack_t **structstack, unsigned int lineno)
{
	stack_t *top = *structstack, *temp = *structstack;
	(void) lineno;

	while (temp)
	{
		if (!temp->next)
		{
			temp->next = top;
			top->prev = temp;
			temp->prev->next = NULL;
			temp->prev = NULL;
			*structstack = temp;
			break;
		}
		temp = temp->next;
	}
}
