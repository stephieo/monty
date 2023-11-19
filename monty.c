#include "monty.h"
/**
 * main - test for monty practice project
 * @argc:
 * @argv:
 *
 */
int main(int argc, char **argv)
{
	size_t n = 0;
	unsigned int line_number = 0;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL; /*this will point to the head/top of stack*/


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if ((holder.mfile = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
		opcode_func = o_s(line_number);

		if (opcode_func != NULL)
			opcode_func(&top, line_number);
		else
			break;
	}
	fclose(holder.mfile);
	cleanup(top);
	exit(EXIT_FAILURE);
	return (0);
}
g_struct holder = {NULL, NULL, NULL,  0, NULL, 1};

