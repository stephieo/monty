#include "monty.h"
/**
 * main - test for monty practice project
 * @argc:
 * @argv:
 *
 */
int main(int argc, char **argv)
{
	/*int i = 0;*/
	size_t n = 0;
	unsigned int line_number = 0;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL; /*this will point to the head/top of stack*/

/*	instruction_t opcode_ls[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if ((holder.mfile = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (holder.status)
	{
		/*handle failure to read lines, empty lines*/
		if (getline(&holder.buffer, &n, holder.mfile) == -1)
		{
			holder.status = 0;
			break;
		} 	

		if (holder.buffer[0] == '#'  || 
			(strspn(holder.buffer, " \t\n\r") ==  strlen(holder.buffer)))
		{
			line_number++;
			continue;
		}
		line_number++;
		/*tokenize and  validate instruction and arguments*/

/*		holder.inst = strtok(holder.buffer, " \t\n\r");
		while (opcode_ls[i].opcode && (strcmp(holder.inst, opcode_ls[i].opcode) != 0))
		{
			i++;
		}
		if (opcode_ls[i].f == NULL)
		{
				fprintf(stderr, "L%d: unknown instruction  %s\n", line_number, holder.inst);
				exit(EXIT_FAILURE);
		}*/
		opcode_func = o_s(line_number);

		if (opcode_func != NULL)
			opcode_func(&top, line_number);
		else
			break;
	}

	cleanup(top);
	exit(EXIT_FAILURE);
	return (0);



}
g_struct holder = {NULL, NULL, NULL,  0, NULL, 1};



