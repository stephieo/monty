#include "monty.h"
/**
* swap - swaps the top 2 elements in a stack
* @stack: pointer to top 
* @line_number: current line number in monty file
*/
void swap(stack_t **stack, unsigned int line_number)
{
    int i = 1, tempno;
    stack_t *counter = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
   

    while (counter->next)
    {
        i++;
        counter = counter->next;
    }

    if (i < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);

    }

    counter = *stack;
    tempno = counter->n;
    counter->n = (counter->next)->n;
    (counter->next)->n = tempno;
}
