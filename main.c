#include "monty.h"

/**
 * main - entry point for program (monty interperter).
 *
 * @argc: number of arguments.
 * @argv: array of argguments.
 *
 * Return: 0 on sucess, 1 on failure.
 */
int main(int argc, char **argv)
{
	stack_t *stack_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_file(argv[1], &stack_head);
	free_stack(&stack_head);

	exit(EXIT_SUCCESS);
}
