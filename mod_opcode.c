#include "monty.h"

/**
 * mod - conputes the remainder
 * of dividing the second top element by the top element of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;
	if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n -= first->n;

	*stack = second;
	second->prev = NULL;

	free(first);
}
