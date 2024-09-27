#include "monty.h"

/**
 * swap - swaps the top elements of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	temp = first->n;
	first->n = second->n;
	second->n = temp;
}
