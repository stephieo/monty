#include "monty.h"
/**
 * push - adds a node to the stack
 * @stack: pointer to head of stack
 * @line_number: current line number in monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *check = NULL;
	stack_t *newnode = malloc(sizeof(stack_t));

	strtol(holder.arg, &check, 10);
	if ((!holder.arg) || (*check != '\0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(holder.buffer);
		free(newnode);
		exit(EXIT_FAILURE);
	}
	holder.value = atoi(holder.arg);
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newnode);
		free(holder.buffer);
		exit(EXIT_FAILURE);
	}
	newnode->n = holder.value;
	newnode->prev = NULL;

	if (*stack == NULL)
	{
		*stack = newnode;
		newnode->next = NULL;
		return;
	}
	newnode->next = *stack;
	(*stack)->prev = newnode;
	*stack = newnode;
}
