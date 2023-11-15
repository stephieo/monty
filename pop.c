#include "monty.h"
/**
* pop - removes the top element from the stack
* @stack: pointer to the top of the stack
* @line_number: current line number of monty file
*/
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if ((*stack) == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n",line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
    (temp->next)->prev = NULL;
    *stack = temp->next;
    free(temp);
}
