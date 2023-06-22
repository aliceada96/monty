#include "monty.h"


static instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
    {"pint", pint};
    {"pop", pop};
    {"swap", swap};
    {"add", add};
    {"nop", nop};
	{NULL, NULL}
};

/**
 * exec_ - Executes monty bytecode instructions.
 * @file: File pointer.
 */
void exec_(FILE *file)
{
	int line_number = 1, i;
    char buff[256];
    int flag = 0;

	stack_t *stack = NULL;

	while (fgets(buff, sizeof(buff), file))
	{
		char *opcode;

		buffer[strcspn(buff, "\n")] = '\0'; /* Remove white space */

		opcode = strtok(buff, " "); /* Tokenize instruction */

		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
}
