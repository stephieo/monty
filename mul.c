#include "monty.h"
/**
* add - adds the to two elements in a stack
* @stack: pointer to top of stack
* @line_number: curent line number of monty file
*/
void mul(stack_t **stack, unsigned int line_number)
{
    int i = 1, result;
    stack_t *counter = *stack;

        if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
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
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
    counter = *stack;
    result = counter->n * (counter->next)->n;
    (counter->next)->n = result;
    pop(stack, line_number);



}
