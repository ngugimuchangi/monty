#include "monty.h"

/**
 * main - checks the code(monty interpreter)
 * @ac: count of args passed to main
 * @av: names of the args
 * Return: 0 upon success
 */

int main(int ac, char **av)
{
	if (ac == 2)
		monty_inter(av);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
