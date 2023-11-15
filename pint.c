#include "monty.h"
/**
* pint - prints  the value at the top of the stack
* @stack: pointer to top
* @line_number: current line number of monty file
*/
void pint(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        free(holder.buffer);
        exit(EXIT_FAILURE);
    }
        
        printf("%d\n", temp->n);

}
