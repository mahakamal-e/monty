#include "monty.h"
/**
 * op_sub - sub two elements
 * @stack_head: head stack
 * @ln_: command number
*/
void op_sub(stack_t **stack_head, unsigned int ln_)
{
	int result;

	if (*stack_head == NULL || (*stack_head)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}
	result = (*stack_head)->next->n - (*stack_head)->n;

	op_pop(stack_head, ln_);

	(*stack_head)->n = result;
}
/**
 * op_div - sub two elements
 * @stack_head: head stack
 * @ln_: command number
*/
void op_div(stack_t **stack_head, unsigned int ln_)
{
	stack_t *tmp;
	int dividend, divisor;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}
	divisor = (*stack_head)->next->n;

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln_);
		exit(EXIT_FAILURE);
	}
	dividend = (*stack_head)->n;
	(*stack_head)->next->n /= dividend;
	tmp = *stack_head;

	*stack_head = (*stack_head)->next;
	free(tmp);
}
/**
 * op_mul - a function that used to multiplies the second top
 * @stack_head: head stack
 * @ln_: line number
 */
void op_mul(stack_t **stack_head, unsigned int ln_)
{
	int number;
	stack_t *tmp;


	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}
	tmp = *stack_head;
	number = (*stack_head)->n;
	(*stack_head)->next->n *= number;
	(*stack_head)->next->prev = NULL;
	free(tmp);
	*stack_head = (*stack_head)->next;
}
