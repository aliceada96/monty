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
	stack_t *new_node;
	int atoi_value;
	char *arg = strtok(NULL, " ");

	if (arg == NULL || !check_int(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	atoi_value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
