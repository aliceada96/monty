#include "monty.h"

char **arg = NULL;
/**
 * main - entry point
 * @argc: number of args
 * @argv: the array of args
 *
 * Return: Exit success if succesful, else exit fail
 *
*/

int main(int argc, char *argv[])
{
FILE *file;
char *filename;

(void) argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", filename);
		return (EXIT_FAILURE);
	}

	exec_(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
