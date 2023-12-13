#include "monty.h"

/**
 * op_print - a function that prints the value at the top of the stack
 * followed by a new line.
 *
 * @stack_head: pointer to the top element in list
 * @ln_: line number of the opcode
 */
void op_print(stack_t **stack_head, unsigned int ln_)
{
	if (stack_head == NULL || *stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln_);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
/**
 * op_pop - a function that removes the top element of the stack.
 *
 * @stack_head: pointer point to top element in the node.
 * @ln_: line number of the opcode.
 */
void op_pop(stack_t **stack_head, unsigned int ln_)
{
	stack_t *temp;

	temp = *stack_head;

	if (stack_head == NULL || *stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln_);
		exit(EXIT_FAILURE);
	}
	*stack_head = temp->next;

	if (*stack_head != NULL)
		(*stack_head)->prev = NULL;
	free(temp);
}
/**
 * op_swap - a function that swaps the top two elements of the stack.
 *
 * @stack_head: pointer point to top element in the node.
 * @ln_: line number of the opcode.
 *
 * Return: void
 */
void op_swap(stack_t **stack_head, unsigned int ln_)
{
	int data_temp;

	if (!(*stack_head) || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}
	data_temp = (*stack_head)->n;
	(*stack_head)->n = (*stack_head)->next->n;
	(*stack_head)->next->n = data_temp;
}
/**
 * op_add - a function that adds the top of two elements.
 *
 * @stack_head: pointer point to top element in the node.
 * @ln_: line number of the opcode.
 *
 * Return: void
 */
void op_add(stack_t **stack_head, unsigned int ln_)
{
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln_);
		exit(EXIT_FAILURE);
	}

	(*stack_head)->next->n += (*stack_head)->n;
	op_pop(stack_head, ln_);
}
/**
 * nop - The opcode nop doesn’t do anything.
 *
 * @stack_head: pointer point to top element in the node.
 * @ln_: line number of the opcode.
 */
void op_nop(stack_t **stack_head, unsigned int ln_)
{
	(void)stack_head;
	(void)ln_;
}
