#include "monty.h"

/**
 *rotate_bottom- rotates the stack to the bottom
 *@h: stack head
 *@c: line_number
 *Return: no return
 */

void rotate_bottom(stack_t **h, __attribute__((unused)) unsigned int c)
{
	stack_t *copy;

	copy = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *h;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*h)->prev = copy;
	(*h) = copy;
}

/**
 *rotate_top- rotates the stack to the top
 *@h: stack head
 *@c: line_number
 *Return: no return
 */

void rotate_top(stack_t **h, __attribute__((unused)) unsigned int c)
{
	stack_t *tmp = *h, *aux;

	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	aux = (*h)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = tmp;
	(*h) = aux;
}

