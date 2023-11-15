#ifndef MONTY_H
#define MONTY_H

/*LIBRARIES*/
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*struct templates*/
/**
 * struct stack_s - dll implementation of a stack 
 * @n: integer
 * @next: link to next element in stack
 * @prev: link to prev element in stack
 *
 * Description- dll node structure for monty project
 */
typedef struct stack_s{
	int n;
	struct stack_s *next;
	struct stack_s *prev;
} stack_t;

/**
 * global_vars - holds global variables
 * @mfile: file pointer for monty file
 * @inst: user inputed instruction
 * @arg: value for push et al in string form
 * @value: value for push et al in integer form
 * @buffer: holds each line per time
 * @status: exit status for program
 */
typedef struct global_vars{
	FILE *mfile;
	char *inst;
	char *arg;
	int value;
	char *buffer;
	int status;
} g_struct;


/**
 * struct instructions_s - opcode  and  its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for monty project
 */
typedef  struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*GLOBAL VARIABLE*/
extern g_struct holder;

/*FUNCTION PROTOTYPES*/
void check_and_open(int arg_no, char *filepath);
void (*o_s(unsigned int line_number))(stack_t **stack, unsigned int line_number);
void stack_setup(stack_t **stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void cleanup(stack_t *stack);

#endif /*MONTY_H*/
