#include "monty.h"


/**
 * execute_monty - executes monty pycodes
 *
 * @file: file containing monty pycodes to be executed
 *
 * Return: nothing
 */
void execute_monty(FILE *file)
{
	char *line = NULL, *opcode;
	size_t line_len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	int i;
	/*I'll handled the array of struct with a function*/
	instruction_t instructions[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};

	while (getline(&line, &line_len, file) != -1)
	{
		opcode = strtok(line, " \n\t");
		line_number++;
		i = 0;

		while (instructions[i].opcode)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
			i++;
		}
		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			free(line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_stack(stack);
}
