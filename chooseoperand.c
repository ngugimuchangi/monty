#include "monty.h"
/**
 * instructchoose - chooses the right operand
 * @structstack: where to save the data
 * @tokens: tokens to read
 * @lineno: line number
 * Return: nothing
 */
void instructchoose(stack_t **structstack, char ***tokens, unsigned int lineno)
{
	void (*operand_code)(stack_t **structstack, unsigned int lineno);
	size_t iterator;

	if (strcmp((*tokens)[0], "push") == 0)
	{
		for (iterator = 0; (*tokens)[iterator] != NULL; iterator++)
		{
			if (iterator == 1)
				checknumber((*tokens)[iterator], lineno);
		}
		if (iterator == 1 && (*tokens)[iterator] == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", lineno);
			exit(EXIT_FAILURE);
		}
	}
	operand_code = choose_operand((*tokens)[0]);
	if (operand_code != NULL)
		operand_code(structstack, lineno);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", lineno, (*tokens)[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * checknumber - check whether string is a number
 * @n: string no
 * @lineno: line mumber
 * Return: 0
 */
void checknumber(char *n, unsigned int lineno)
{
	size_t i;

	for (i = 0; n[i] != '\0'; i++)
	{
		if (i == 0 && n[i] == '-')
			continue;
		else if (!((n[i] >= '0' && n[i] <= '9') || (n[i] == '-')))
		{
			fprintf(stderr, "L%u: usage: push integer\n", lineno);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(n);
}
/**
 * choose_operand - choose right op to use
 * @code: string number
 * Return: nothing
 */
void (*choose_operand(char *code))(stack_t **stack, unsigned int linenumber)
{
	int i;
	instruction_t opcodes[] = {
		{"push", pushstack},
		{"pall", pallstack},
		{"pint", peekstack},
		{NULL, NULL}};

	if (code[0] == '#')
		return (comS);

	for (i = 0; opcodes[i].opcode != NULL; i++)
		if (strcmp(code, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	return (opcodes[i].f);
}
