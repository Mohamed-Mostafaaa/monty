#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @c: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */

int exe(char *content, stack_t **stack, unsigned int c, FILE *file)
{
	instruction_t opst[] = {
		{"push", mohamed_push},
		{"pall", mohamed_pall},
		{"pop", mohamed_pop},
		{"swap", mohamed_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pint", print_top},
		{"nop", do_nothing},
		{"pchar", print_char},
		{"pstr", print_int},
		{"rotl", rotate_top},
		{"rotr", rotate_bottom},
		{"queue", qu},
		{"stack", st},
		{NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, c);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}