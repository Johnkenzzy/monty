#include "monty.h"


/**
 * push - pushes a new stack node to the top-end of the stack
 *
 * @stack: pointer to stack struct
 * @line_number: the file line number where the function is called
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack_node;
	char *arg = strtok(NULL, " \n\t");

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_stack_node = malloc(sizeof(stack_t));
	if (!new_stack_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_stack_node->n = atoi(arg);
	new_stack_node->prev = NULL;
	new_stack_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_stack_node;

	*stack = new_stack_node;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 *
 * @stack: pointer to stack struct
 * @line_number: the file line number where the function is called
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_stack_node = *stack;
	(void)line_number;

	while (current_stack_node)
	{
		printf("%d\n", current_stack_node->n);
		current_stack_node = current_stack_node->next;
	}
}
