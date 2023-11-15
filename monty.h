#ifndef MONTY_H
#define MONTY_H


/*LIBRARIES */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*STRUCT DEFINITIONS*/

/**
 * struct stack_s -doubly linked list representation of a stack or queue
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * 
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instructions_s opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function 
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * global_vars - holds global variables
 * @mfile: file pointer for monty file
 * @optoken: user inputed instruction
 * @arg: value for push in string form
 * @value: value for push et al in integer form
 * @buffer: holds each line per time
 * @status: exit flag for program
 */
typedef struct global_vars{
	FILE *mfile;
	char *inst;
	char *arg;
	int value;
	char *buffer;
	int status;
} g_struct;


/*GLOBAL VARIABLES*/
extern g_struct holder;

/*FUNCTION PROTOTYPES*/
void check_and_open(int arg_no, char *filepath);
void(*o_s(unsigned int line_number))(stack_t **stack, unsigned int line_number);
void stack_setup(stack_t **stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void cleanup(stack_t *stack);

#endif /*MONTY_H*/
