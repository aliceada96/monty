#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: A pointer to the top of stack
 * @line_number: current line number in monty file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - emoves the top element of the stack.
 * @stack: A pointer to the top of stack
 * @line_number: current line number in monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * swap - Swaps 2 top elements in stack
 * @stack: pointer to top node of stack
 * @line_number: current line number in monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
}
