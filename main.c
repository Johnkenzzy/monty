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
		usage_error();

	file = fopen(argv[1], "r");
	if (file == NULL)
		file_error(argv[1]);

	execute_monty(file);

	fclose(file);
	return (0);
}
