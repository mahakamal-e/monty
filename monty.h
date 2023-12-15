#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>

extern char *value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

FILE *open_file(const char *file_name, const char *mode_);
void interpret_monty_script(FILE *file_name, stack_t **stack_head);
int execute_file(char *file_name, stack_t **stack_head);

void execute_opcode(stack_t **stack_head, char *opcode_, unsigned int ln_);

void free_stack(stack_t **stack_head);
void op_pall(stack_t **stack_head,  __attribute__((unused)) unsigned int ln_);
void op_push(stack_t **stack_head,  unsigned int ln_);
int convert_to_integer(char *input, unsigned int ln_);


void op_print(stack_t **stack_head, unsigned int ln_);
void op_pop(stack_t **stack_head, unsigned int ln_);
void op_swap(stack_t **stack_head, unsigned int ln_);
void op_add(stack_t **stack_head, unsigned int ln_);
void op_nop(stack_t **stack_head, unsigned int ln_);
void op_sub(stack_t **stack_head, unsigned int ln_);
void op_div(stack_t **stack_head, unsigned int ln_);
void op_pchar(stack_t **stack_head, unsigned int ln_);
void op_pstr(stack_t **stack_head, unsigned int ln_);
void op_mul(stack_t **stack_head, unsigned int ln_);

#endif
