#include "monty.h"
/**
 * check_and_open - checks for correct args and opens montyfile
 * @arg_no: argument count
 * @filepath: filepath of monty file
 *
 */
void check_and_open(int arg_no, char *filepath)
{
	if (arg_no != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	holder.mfile = fopen(filepath, "r");
	if (holder.mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		printf("error is %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

}
