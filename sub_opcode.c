#include "monty.h"

/**
 * sub - subtracts the top element from second top of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	second->n -= first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
