#include "monty.h"
#include <stdio.h>

/**
 * execute_monty - executes monty opcodes
 *
 * @file: file containing monty opcodes to be executed
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

	while ((getline(&line, &line_len, file)) != -1)
	{

		opcode = strtok(line, " \n\t");
		line_number++;
		
		if (!opcode || opcode[0] == '\0' || opcode[0] == '#')
			continue;

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
