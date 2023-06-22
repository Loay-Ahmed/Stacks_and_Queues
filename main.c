#include "monty.h"

vars var;

/**
 * main - the main function and starting point
 *
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 (success), 1 (fail)
 */

int main(int argc, char *argv[])
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	var.f = fopen(argv[1], "r");
	if (!var.f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}
	while (getline(&var.buf, &var.tmp, var.f ) != EOF) 
	{
		opcode = strtok(var.buf, " \r\t\n");
		if (opcode != NULL)
		{
			if (call_function(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		}
		var.line_number++;
	}

	free_all();
	return (EXIT_SUCCESS);
}
