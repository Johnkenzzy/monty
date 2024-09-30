#include "monty.h"

/**
 * rotr - rotates the last element to the top of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;
	(void)line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	last = *stack;
	second_last = NULL;

	while (last->next)
	{
		second_last = last;
		last = last->next;
	}

	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
