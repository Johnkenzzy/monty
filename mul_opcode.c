#include "monty.h"

/**
 * mul - multiplies the second top  with second top elements of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	second->n = second->n * first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
