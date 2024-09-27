#include "monty.h"

/**
 * pop - removes the element at the top of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_top_node;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_top_node = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(stack_top_node);
}
