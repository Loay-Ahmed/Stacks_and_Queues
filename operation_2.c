#include "monty.h"

/**
 * swap - Swaps the last two integers
 * @stack: Double linked list
 * @line_number: The line number in the file
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	while ((*stack)->next)
		(*stack) = (*stack)->next;
	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->prev->n;
	(*stack)->prev->n = (*stack)->n;
	(*stack)->n = tmp;
}

/**
 * add - Adds the last two number in the list
 * @stack: Double linked list
 * @line_number: The line number of the file
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = (*stack)->prev->n + (*stack)->n;
	pop(stack, line_number);
}
