#include "monty.h"
/**
 * pop - removes the top element in a stack
 * @stack: pointer to top of stack
 * @line_number: line of opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		holder.status = 0;
	}

	if ((*stack)->next != NULL)
	{
		temp = (*stack)->next;
		temp->prev = NULL;
		free(*stack);
		*stack = temp;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}

}
