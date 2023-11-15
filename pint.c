#include "monty.h"
/**
 * pint - print the top element in a stack
 * @stack: pointer to head of stack
 * @line_number: line of current instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		holder.status = 0;
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}
