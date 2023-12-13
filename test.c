#include "monty.h"

/**
 * is_int - .
 * @value: .
 * Return: .
*/

int is_int(char *value)
{
	char *ptr = value;

	if (value == NULL)
		return (0);
	if (*ptr == '-')
		ptr++;
	while (*ptr != '\0')
	{
		if (*ptr >= '0' && *ptr <= '9')
			ptr++;
		else
			return (0);
	}
	return (1);
}
/**
 * free_list - .
 * @stack: .
 * Return: .
*/
void free_list(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *free_me;

	while (curr != NULL)
	{
		free_me = curr;
		curr = curr->next;
		free(free_me);
	}
	*stack = NULL;
}
/**
 * push - .
 * @stack: .
 * @line_number: .
 * Return: .
*/

void op_push(stack_t **stack_head,  unsigned int ln_)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int is_num, number;

	is_num = is_int(value);
	if ((!is_num))
	{
		free_list(&new_node);
		free_list(stack_head);
		fprintf(stderr, "L%d: usage: push integer\n", ln_);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	number = atoi(value);
	new_node->n = number;
	new_node->prev = NULL;
	if (*stack_head == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack_head;
		(*stack_head)->prev = new_node;
	}
	*stack_head = new_node;
}
