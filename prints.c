#include "monty.h"

/**
 * print_char - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @c: line_number
 * Return: no return
 */

void print_char(stack_t **head, unsigned int c)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * print_top - prints the top
 * @h: stack head
 * @c: line_number
 * Return: no return
 */

void print_top(stack_t **h, unsigned int c)
{
	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * print_int - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @c: line_number
 * Return: no return
 */

void print_int(stack_t **head, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

/**
 *do_nothing- nothing
 *@h: stack head
 *@c: line_number
 *Return: no return
 */

void do_nothing(stack_t **h, unsigned int c)
{
	(void)c;
	(void)h;
}