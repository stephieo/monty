#include "monty.h"
/**
* mod - divides the second top element by the top element in a stack
* @stack: pointer to top of stack
* @line_number: curent line number of monty file
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int i = 1, result;
	stack_t *counter = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
    
    counter = *stack;
    if (counter->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
    result = (counter->next)->n % counter->n ;
    (counter->next)->n = result;
    pop(stack, line_number);

}
