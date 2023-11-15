#include "monty2.h"
/**
 * stack_setup - initializes an sempty stack
 * @stack: pointer to stack head
 */
void stack_setup(stack_t **stack)
{
	stack_t *init = malloc(sizeof(stack_t));

	if (init == NULL)
		holder.status = 0;

	*stack = init;
	init->n = 0;
	init->next = NULL;
	init->prev = NULL;

}
