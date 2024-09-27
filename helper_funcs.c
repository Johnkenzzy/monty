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



/**
 * is_number - checks if a string is a valid integer
 *
 * @str: string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
