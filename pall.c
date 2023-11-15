#include "monty.h"
/**
 * pall - prints the elements in stack
 * @stack: address of head of stack
 * @line_number: line number where command is located
 */
void pall(stack_t **stack, unsigned int line_number)
{
	size_t i;
	const stack_t *counter = *stack;

	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	for (i = 1; counter->next != NULL; i++)
	{
		printf("%d\n", counter->n);
		counter = counter->next;
	}
	printf("%d\n", counter->n);
	printf("0\n");

}
