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
