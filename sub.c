#include "monty.h"
/**
* sub - subtracts the top element from the second top element in a stack
* @stack: pointer to top of stack
* @line_number: curent line number of monty file
*/
void sub(stack_t **stack, unsigned int line_number)
{
    int i = 1, result;
    stack_t *counter = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
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
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
    counter = *stack;
    result = (counter->next)->n - counter->n ;
    (counter->next)->n = result;
    pop(stack, line_number);



}
