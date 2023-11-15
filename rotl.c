#include "monty.h"
/**
* rotl - rotates a stack to  the top
* @stack: pointer to top of stack
* @line_number: current line number of monty file
*/
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    int i = 1;

    (void)line_number;

    while (temp->next != NULL)
    {
        i++;
        temp = temp->next;
    }

    if (*stack == NULL || i == 1)
    {
        return;
    }
    else
    {
        temp->next = *stack;
        printf("last node %d is now pointing to %d\n", temp->n, temp->next->n);
        (*stack)->prev = temp;
        printf("prev of old top node is now %d\n", (*stack)->prev->n);
        *stack = (*stack)->next;
        printf("top node is now %d\n",(*stack)->n);
        (*stack)->prev = NULL;
        (temp->next)->next = NULL;
    }


}
