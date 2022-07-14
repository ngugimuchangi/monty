#include "monty.h"
/**
 * popstack - remove top element
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void popstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *temp = *structstack;

	if (!temp)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineno);
		exit(EXIT_FAILURE);
	}
	*structstack = temp->next;
	free(temp);
}

/**
 * swapstack - swaps the two top elements of the stack
 * @structstack: address of the first node
 * @lineno: line number
 *
 * Return: nothing
 */
void swapstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *current = *structstack, *next;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineno);
		exit(EXIT_FAILURE);
	}
	next = current->next;
	*structstack = next;
	current->next = next->next;
	if (current->next)
		current->next->prev = current;
	next->prev = NULL;
	next->next = current;
}

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
