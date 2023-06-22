#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: Pointer to stack.
 * @line_number: current line number in monty file
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * nop - doesn’t do anything.
 * @stack:Pointer to stack.
 * @line_number: current line number in monty file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
