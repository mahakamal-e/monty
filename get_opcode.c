#include "monty.h"

/**
 * execute_opcode - a function that executes the opcode
 *
 * @stack_head: a pointer to the top element in stack (head).
 * @opcode_: opcode.
 * @ln_: line number variable helps identify the specific line within
 * the script that is being processed.
 *
 * Return: void
 */
void execute_opcode(stack_t **stack_head, char *opcode_, unsigned int ln_)
{
	instruction_t func_select[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_print},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
	};
	unsigned int i;

	if (opcode_[0] == '#')
		return;
	for (i = 0; func_select[i].opcode != NULL; i++)
	{
		if (strcmp(opcode_, func_select[i].opcode) == 0)
		{
			func_select[i].f(stack_head, ln_);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln_, opcode_);
}
