#include "monty2.h"
/**
 * o_s - compares string to opcodes
 * @line_num: line from monty file
 *
 * Return: NULL if invalid, pointer to function if valid
 */
void(*o_s(unsigned int line_num))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t opcode_ls[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"nop", nop}, {"swap", swap},
		{"add", add}, {"sub", sub},
		{"div", my_div}, {"mul", mul},
		{"mod", mod}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};


/*	if (holder.buffer[0][0] == '#')*/
	holder.inst = strtok(holder.buffer, " \t\n\r");
	while (opcode_ls[i].opcode && (strcmp(holder.inst, opcode_ls[i].opcode) != 0))
	{
		i++;
	}

	holder.arg = strtok(NULL, " \t\n");
	if (opcode_ls[i].f == NULL)
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, holder.inst);

	return (opcode_ls[i].f);
}
