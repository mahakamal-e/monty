#include "monty.h"
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
