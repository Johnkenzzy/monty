#include "monty.h"


/**
 * free_stack - frees entire stack, one stack node at a time
 * @stack: stack to be freed
 *
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
