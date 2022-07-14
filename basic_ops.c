#include "monty.h"

int num[2];

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
	newnode->n = num [1];
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
