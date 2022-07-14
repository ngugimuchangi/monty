#include "monty.h"

int num;

/**
 * pushstack- inserts a value to stack
 * @structstack: stack to insert
 * @lineno: linemubmer
 * Return: Nothing
 */

void pushstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	(void) lineno;

	if (newnode == NULL)
		return;
	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*structstack != NULL)
	{
		newnode->next = *structstack;
		(*structstack)->prev = newnode;
	}
	*structstack = newnode;
}

/**
 * pallstack- displays the stack
 * @structstack: stack to display
 * @lineno: line of code
 * Return: 0
 */
void pallstack(stack_t **structstack, unsigned int lineno)
{
	stack_t *temp = *structstack;

	(void) lineno;
	if (*structstack == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * peekstack- prints top of stack wo removing it
 * @structstack: stack
 * @lineno: line of code
 * Return: 0
 */
void peekstack(stack_t **structstack, unsigned int lineno)
{
	if (*structstack != NULL)
		printf("%d\n", (*structstack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineno);
		exit(EXIT_FAILURE);
	}
}
