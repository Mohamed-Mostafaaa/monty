#include "monty.h"

/**
 * mohamed_pall - prints the stack
 * @head: stack head
 * @c: no used
 * Return: no return
 */

void mohamed_pall(stack_t **head, unsigned int c)
{
	stack_t *h;
	(void)c;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * mohamed_push - add node to the stack
 * @stack: stack head
 * @ln: line_number
 * Return: no return
 */

void mohamed_push(stack_t **stack, unsigned int ln)
{
	int n, j = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				f = 1;
		}
		if (f == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}

/**
 * mohamed_pop - prints the top
 * @head: stack head
 * @c: line_number
 * Return: no return
 */
void mohamed_pop(stack_t **head, unsigned int c)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * mohamed_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @ln: line_number
 * Return: no return
 */

void mohamed_swap(stack_t **stack, unsigned int ln)
{
	stack_t *h;
	int len = 0, aux;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

