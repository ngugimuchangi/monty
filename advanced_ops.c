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
	if (temp->n < 0 || temp->n > 255)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineno);
		exit(EXIT_FAILURE);
	}
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
		if (temp->n <= 0 || temp->n > 255)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * pstr - prints all numbers in stack as ASCII characters
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void rotl(stack_t **structstack, unsigned int lineno)
{
	(void) structstack;
	(void) lineno;
}

/**
 * pstr - prints all numbers in stack as ASCII characters
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void rotr(stack_t **structstack, unsigned int lineno)
{
	(void) structstack;
	(void) lineno;
}
