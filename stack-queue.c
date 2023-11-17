#include "monty.h"

/**
 * st - prints the top
 * @head: stack head
 * @c: line_number
 * Return: no return
 */

void st(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
	bus.lifi = 0;
}

/**
 * qu - prints the top
 * @head: stack head
 * @c: line_number
 * Return: no return
 */

void qu(stack_t **head, unsigned int c)
{
	(void)head;
	(void)c;
	bus.lifi = 1;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */

void add_queue(stack_t **head, int n)
{
	stack_t *nw, *aux;

	aux = *head;
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		printf("Error\n");
	}
	nw->n = n;
	nw->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = nw;
		nw->prev = NULL;
	}
	else
	{
		aux->next = nw;
		nw->prev = aux;
	}
}

/**
 * add_node - add node to the head stack
 * @h: head of the stack
 * @n: new_value
 * Return: no return
 */

void add_node(stack_t **h, int n)
{

	stack_t *nw, *aux;

	aux = *h;
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = nw;
	nw->n = n;
	nw->next = *h;
	nw->prev = NULL;
	*h = nw;
}

