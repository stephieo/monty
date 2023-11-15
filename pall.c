#include "monty.h"
/**
* pall - prints elements in stack
* @stack: pointer to top
* @line_number: current line number of monty file
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack == NULL)
		return;

	while (temp->next != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

	printf("%d\n", temp->n);
	printf("0\n");

}
