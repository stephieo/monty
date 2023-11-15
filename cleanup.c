#include "monty2.h"
/**
 * cleanup - collection of cleanup function calls
 * @stack: head of stack
 */
void cleanup(stack_t *stack)
{
	free(holder.buffer);
	fclose(holder.mfile);
	free_stack(stack);
}
