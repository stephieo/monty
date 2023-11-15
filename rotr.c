#include "monty.h"
/**
* rotr - rotates a stack to  the  bottom
* @stack: pointer to top of stack
* @line_number: current line number of monty file
*/
void rotr(stack_t **stack, unsigned int line_number)
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
        (*stack)->prev = temp;
        temp->next = *stack;
        temp = temp->prev;
        temp->next->prev = NULL;
        temp->next = NULL;
        (*stack) = (*stack)->prev;        
        printf("top node is now %d\n",(*stack)->n);
        printf("last node is now %d\n",temp->n);
    }


}
