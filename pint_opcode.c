#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
