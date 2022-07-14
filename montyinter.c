#include "monty.h"
#define _GNU_SOURCE

/**
 * monty_inter - fn resembles monty interpreter
 * @av: arg array
 * Return: 0 upon success
 */

void monty_inter(char **av)
{
	char *spec_file = av[1], *buf = NULL, **tokens = NULL;
	size_t len = 0, lineno = 1;
	ssize_t readline;
	stack_t *structstack = NULL;
	FILE *open_f;

	open_f = fopen(spec_file, "r");

	if (open_f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", spec_file);
		exit(EXIT_FAILURE);
	}
	for (lineno = 1; (readline = getline(&buf, &len, open_f)) != -1; lineno++)
	{
		line_token(&buf, &tokens, readline);
		if (tokens != NULL)
			instructchoose(&structstack, &tokens, lineno);
		freetokens(&tokens);
	}

	fclose(open_f);
	if (buf != NULL)
		free(buf);
	free_structstack(structstack);
}

/**
 * freetokens - function that frees the tokens
 * @tokens: to be freed
 * Return: 0
 */

void freetokens(char ***tokens)
{
	if (*tokens != NULL)
	{
		free(*tokens);
		*tokens = NULL;
	}
}
/**
 * free_structstack - frees the stack
 * @structstack: stack to free
 * Return: Nothing
 */
void free_structstack(stack_t *structstack)
{
	stack_t *new;

	if (structstack != NULL)
	{
		while (structstack != NULL)
		{
			new = structstack->next;
			free(structstack);
			structstack = new;
		}
	}
}
