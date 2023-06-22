#include "monty.h"

/**
 * pall - prints elements of the stack
 * @stack: Pointer to stack.
 * @line_number: current line number in monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * check_int - Check if variable provided for opcode is an int
 * @str: - Str to check.
 *
 * Return: true else false.
 */
bool check_int(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}

	return (true);
}

/**
 * push - inserts new element at the top of stack.
 * @stack: stack struct
 * @line_number: Element added to stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *temp;
	int i;

    new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; arg[1][i]; i++)
	{
		if (arg[1][i] == '-' && i == 0)
			continue;
		if (arg[1][i] < '0' || arg[1][i] > '9')
		{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		}
	}
	new_node->n = atoi(arg[1]);
	if (mode_check(*stack) == STACK) /* STACK */
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;
		if (temp)
			temp->prev = new_node;
		(*stack)->next = new_node;
	}
	else /* QUEUE mode */
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = NULL;
		temp->next = new_node;
	}
}
