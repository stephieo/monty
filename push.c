#include "monty.h"
/**
* push  - adds a new node to the stack
* @stack: pointer to top of stack
* @line_number: current line number in monty file
*/
void push(stack_t **stack, unsigned int line_number)
{
    char *check = NULL;
    stack_t *newnode = NULL;

    strtol(holder.arg, &check, 10);

    if (holder.arg == check)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }else
    {
        holder.value = atoi(holder.arg);
    }

    newnode = malloc(sizeof(stack_t));
    if (!newnode)
    {
        fprintf(stderr,"Malloc Error\n");
        free(holder.buffer);
        free(newnode);
        exit(EXIT_FAILURE);
    }

    newnode->n = holder.value;
    newnode->prev = NULL;
    if ((*stack) == NULL)
    {
        *stack = newnode;
        newnode->next = NULL;
        return;
    }
    newnode->next = *stack;
    (*stack)->prev = newnode;
    *stack = newnode;
}
