#include "monty.h"

/**
 * op_push - a function that used to push element into stack.
 *
 * @stack_head: a pointer the first element.
 * @ln_: line_number stands for the line number within the Monty script file
 * where the current operation is being processed or executed.
 *
 * Return: void
 */
void op_push(stack_t **stack_head,  unsigned int ln_)
{
	stack_t *n_node;
	char *input;
	int data;

	input = strtok(NULL, " \t\n");

	if (!input)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln_);
		exit(EXIT_FAILURE);
	}
	/*data = atoi(input);*/
	data = convert_to_integer(input, ln_);

	n_node = (stack_t *) malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	n_node->n = data;
	n_node->prev = NULL;
	n_node->next = *stack_head;

	if (*stack_head != NULL)
	{
		(*stack_head)->prev = n_node;
	}

	*stack_head = n_node;
}
/**
 * convert_to_integer - a function that Converts a string to an integer value.
 *
 * @input: A pointer to the string that needs to be converted to an integer.
 * @ln_: Line number from the input source.
 *
 * Return: An integer value converted from the provided string.
 */
int convert_to_integer(char *input, unsigned int ln_)
{
	char *endptr;
	int data = strtol(input, &endptr, 10);

	if (endptr == input || *endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln_);
		exit(EXIT_FAILURE);
	}
	return (data);
}

/**
 * op_pall - a function that used to print all elements in linkedlist
 * @stack_head: a pointer to top element in stack
 * @ln_: line_number stands for the line number within the Monty script file
 * where the current operation is being processed or executed.
 *
 * Return: void
 */
void op_pall(stack_t **stack_head,  __attribute__((unused)) unsigned int ln_)
{
	stack_t *head;

	head = *stack_head;

	while (head != NULL)
	{
		fprintf(stdout, "%d\n", head->n);
		head = head->next;
	}
}

/**
 * free_stack - free stack (free nodes in linkedlist).
 * @stack_head: head pointer to first node (top in stack).
 */
void free_stack(stack_t **stack_head)
{
	stack_t *temp;
	stack_t *h;

	h = *stack_head;

	while (h != NULL)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
	*stack_head = NULL;
}
