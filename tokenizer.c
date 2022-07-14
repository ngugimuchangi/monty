#include "monty.h"
/**
 * line_token - starts the monty inter
 * @buf: temp storage for dataline
 * @tokens: where the opcode(push,pall etc) is stored
 * @readline: no of chars to read
 * Return: Nothing
 */

void line_token(char **buf, char ***tokens, ssize_t readline)
{
	size_t n;

	if (readline > 0)
	{
		for (n = 0; (*buf)[n] == ' ' || (*buf)[n] == '\t'; n++)
		{
			if ((*buf)[n + 1] == '\n')
				return;
		}
	}

	if (**buf != '\n')
	{
		dellineno(buf);
		tokenizer(buf, tokens);
	}
}
/**
 * dellineno - delete newline
 * @buf: temp storage
 * Return: 0
 */
void dellineno(char **buf)
{
	int n;

	for (n = 0; (*buf)[n] != '\0'; n++)
		;
	(*buf)[n - 1] = '\0';
}

/**
 * tokenizer - places the buf in tokens
 * @buf: temp storage
 * @tokens: where to place buf
 * Return: nothing
 */
void tokenizer(char **buf, char ***tokens)
{
	char *token = NULL, *delim = " \n\t";
	size_t i, num;

	token = strtok(*buf, delim);
	if (strcmp(token, "push") == 0)
		num = 3;
	else
		num = 2;
	*tokens = malloc(sizeof(char *) * num);
	for (i = 0; token != NULL && i <= num - 2; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, delim);
	}
	(*tokens)[i] = NULL;
}
