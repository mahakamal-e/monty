#include "monty.h"
/**
 * op_pchar - a function that prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack_head: head pointer point to top element.
 * @ln_: line number
 */
void op_pchar(stack_t **stack_head, unsigned int ln_)
{
	int value;
	/*stack_t *temp;*/

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln_);
		exit(EXIT_FAILURE);
	}
	value = (*stack_head)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln_);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);

	/*temp = *stack_head;*/
	/**stack_head = (*stack_head)->next;*/
	/*free(temp);*/
}
/**
 * op_pstr - function that used to prints the string starting
 * at the top of the stack, followed by a new line.
 *
 * @stack_head: head pointer point to top element.
 * @ln_: line number
 */
void op_pstr(stack_t **stack_head, unsigned int ln_)
{
	stack_t *tmp;
	int val;
	tmp = *stack_head;

	while (tmp != NULL && tmp->n != 0)
	{
		val = tmp->n;
		if (val < 0 || val > 127)
		{
			fprintf(stderr, "L%d: can't pstr, value out of range\n", ln_);
			exit(EXIT_FAILURE);
		}
		putchar((char)val);
		tmp = tmp->next;
	}
	putchar('\n');
}
