#include "monty.h"
/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to top of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = stack;

	if (stack == NULL)
	{
		return;
	}

	while (temp->next)
	{
		temp = temp->next;
		free(temp->prev);
		if (temp->next == NULL)
			break;
	}
	free(temp);
	stack = NULL;
}
