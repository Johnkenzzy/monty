#include "monty.h"

int mode = 0;

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
	stack_t *new_stack_node, *temp;
	char *arg = strtok(NULL, " \n\t");

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_stack_node = malloc(sizeof(stack_t));
	if (!new_stack_node)
		malloc_error();

	new_stack_node->n = atoi(arg);
	new_stack_node->prev = NULL;
	new_stack_node->next = NULL;
	if (mode == 0)
	{
		new_stack_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_stack_node;
		*stack = new_stack_node;
	}
	else
	{
		if (*stack == NULL)
			*stack = new_stack_node;
		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			temp->next = new_stack_node;
			new_stack_node->prev = temp;
		}
	}
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


/**
 * stack - sets the mode to LIFO (stack behavior)
 * @stack: pointer to the stack (not used)
 * @line_number: line number in the bytecode file (not used)
 *
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 0;
}

/**
 * queue - sets the mode to FIFO (queue behavior)
 * @stack: pointer to the stack (not used)
 * @line_number: line number in the bytecode file (not used)
 *
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mode = 1;
}
