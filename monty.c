#include "monty.h"


/**
 * main - monty bytecode interpreter
 * @argc: argument count (must be 2)
 * @argv: array of arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	size_t n = 0;
	unsigned int line_num = 0;
	void (*opcode_func)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL;

	check_and_open(argc, argv[1]);
	while (holder.status)
	{
		if (getline(&holder.buffer, &n, holder.mfile) == -1)
		{
			holder.status = 0;
			break;
		}
		if (strspn(holder.buffer, " \t\n\r") == strlen(holder.buffer))
		{
			line_num++;
			continue;
		}

		if (holder.buffer[0] == '#')
		{
			line_num++;
			continue;
		}

		line_num++;
		opcode_func = o_s(line_num);
		if (opcode_func != NULL)
			opcode_func(&top, line_num);
		else
			break;
	}
	cleanup(top);
	exit(EXIT_FAILURE);
	return (0);
}
g_struct holder = {NULL, NULL, NULL,  0, NULL, 1};
