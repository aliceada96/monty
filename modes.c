#include "monty.h"
#include <string.h>

/**
 * free_stack - Frees the stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue)
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_stack - Initializes a stack_t stack
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * mode_check - Checks if linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int mode_check(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
