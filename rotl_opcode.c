#include "monty.h"

/**
 * rotl - rotates the top element to last,
 * and the second becomes top element of the stack
 *
 * @stack: current top node of stack
 * @line_number: line in fille where cammand function was called
 *
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *temp;
	(void)line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	top = (*stack)->next;
	temp = *stack;

	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->next = NULL;
	*stack = top;
}
