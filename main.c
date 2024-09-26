#include "monty.h"

/**
 * main - Program entry point
 *
 * @argc: number of arguments in argument array
 * @argv: argument array
 *
 * Return: 0 (always successful)
 */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute_monty(file);

	fclose(file);
	return (0);
}
