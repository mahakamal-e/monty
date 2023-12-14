#include "monty.h"
/**
 * op_sub - sub two elements
 * @stack_head: head stack
 * @ln_: command number
*/
void op_sub(stack_t **stack_head, unsigned int ln_)
{
	stack_t *top;
	stack_t *second;
	int result;

	if (*stack_head == NULL || (*stack_head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}
	top = *stack_head;
	second = top->prev;

	result = second->n - top->n;

	second->n = result;
	*stack_head = second;
	free(top);
}
/**
 * op_div - sub two elements
 * @stack_head: head stack
 * @ln_: command number
*/
void op_div(stack_t **stack_head, unsigned int ln_)
{
	stack_t *tmp;
	int number;

	if (*stack_head == NULL || (*stack_head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}

	if ((*stack_head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_);
		exit(EXIT_FAILURE);
	}
	tmp = *stack_head;
	number = (*stack_head)->n;
	(*stack_head)->next->n /= number;
	(*stack_head)->next->prev = NULL;
	free(tmp);
	*stack_head = (*stack_head)->next;
}
