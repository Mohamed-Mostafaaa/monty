#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void prStack(stack_t **, unsigned int);
void add_Stack(stack_t **, unsigned int);
void add_Queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void op_swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void op_add(stack_t **, unsigned int);
void op_sub(stack_t **, unsigned int);
void op_div(stack_t **, unsigned int);
void op_mul(stack_t **, unsigned int);
void op_mod(stack_t **, unsigned int);

/*String operations*/
void medo_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void str_error(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
