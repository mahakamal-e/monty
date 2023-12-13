#include "monty.h"


/**
 * open_file - a function that used to handle opening and error.
 *
 * @file_name: name of the file.
 * @mode_: mode of opening the file.
 *
 * Return: Pointer to FILE on success
 */

FILE *open_file(const char *file_name, const char *mode_)
{
	FILE *fd = fopen(file_name, mode_);

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * interpret_monty_script - afunction that read and process lines from file.
 *
 * @file_name: a pointer to opened file.
 * @stack_head: a pointer to the top node in the stack.
 *
 * Return: void
 */
void interpret_monty_script(FILE *file_name, stack_t **stack_head)
{
	char *opcode = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file_name)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\r\n\a\"");

		if (opcode != NULL)
			execute_opcode(stack_head, opcode, line_number);
	}
	free(line);
}
/**
 * execute_file - a function that  responsible for
 * managing the Monty file processing workflow.
 *
 * @file_name: file name.
 * @stack_head: a pointer to the top node in the stack.
 *
 * Return: Exit with success otherwise Failure.
 */
int execute_file(char *file_name, stack_t **stack_head)
{
	FILE *fd = open_file(file_name, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (EXIT_FAILURE);
	}
	interpret_monty_script(fd, stack_head);

	fclose(fd);
	return (EXIT_SUCCESS);
}
