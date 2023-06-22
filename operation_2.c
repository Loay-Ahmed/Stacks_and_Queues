#include "monty.h"

/**
 * swap - Swaps the last two integers
 * @stack: Double linked list
 * @line_number: The line number in the file
 * Return: Nothing
 */
void swap(stac_t **stack, unsigned int line_numebr)
{
	int tmp;

	if (!*stack || !(*satck)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - Adds the last two number in the list
 * @stack: Double linked list
 * @line_number: The line number of the file
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
