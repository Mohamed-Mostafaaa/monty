#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/syscall.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int exe(char *content, stack_t **head, unsigned int c, FILE *file);
void mohamed_push(stack_t **head, unsigned int ln);
void mohamed_pall(stack_t **head, unsigned int c);
void mohamed_pop(stack_t **head, unsigned int c);
void mohamed_swap(stack_t **stack, unsigned int ln);
void op_add(stack_t **head, unsigned int c);
void op_sub(stack_t **head, unsigned int c);
void op_div(stack_t **head, unsigned int c);
void op_mod(stack_t **head, unsigned int c);
void op_mul(stack_t **head, unsigned int c);
void st(stack_t **head, unsigned int c);
void qu(stack_t **head, unsigned int c);
void add_node(stack_t **h, int n);
void add_queue(stack_t **head, int n);
void rotate_bottom(stack_t **h, __attribute__((unused)) unsigned int c);
void rotate_top(stack_t **h, unsigned int c);
void free_stack(stack_t *head);
void print_top(stack_t **h, unsigned int c);
void print_char(stack_t **head, unsigned int c);
void print_int(stack_t **head, unsigned int c);
void do_nothing(stack_t **h, unsigned int c);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);

#endif /* MONTY_H */

