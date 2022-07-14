#include "monty.h"
/**
 * addstack - adds the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void addstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n += current->n;
	popstack(structstack, lineno);
}

/**
 * substack - subtracts the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void substack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n -= current->n;
	popstack(structstack, lineno);
}

/**
 * divstack - divides the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void divstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n /= current->n;
	popstack(structstack, lineno);
}

/**
 * mulstack - multiplies the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void mulstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n *= current->n;
	popstack(structstack, lineno);
}

/**
 * modstack - computes mod of the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void modstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	if (next->n < 0)
		next->n = current->n;
	else
		next->n %= current->n;
	popstack(structstack, lineno);
}
