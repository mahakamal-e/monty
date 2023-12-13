#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *operation;
	int value;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	operation = strtok(NULL, " \t\n");
	if (operation == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = parse_value(operation, line_number);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all values on the stack from the top
 * @stack: double pointer to the first node
 * @line_number: line number of the operation
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	(void)(line_number);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
/**
 * parse_value - parses the value
 * @operation: operation
 * @line_number: line number
 * Return: value
 */

int parse_value(char *operation, unsigned int line_number)
{
	char *endptr;
	int value = strtol(operation, &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	return (value);
}
