#include "monty.h"
/**
 * execute - find the desired opcode and call the related funciton
 * @content: a single line in the monty file
 * @stack: pointer to
 * @counter:
 * @fp:
 *
 */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *op, *arg;
	unsigned int i, j, flag;

	op = arg = NULL;
	i = j = flag = 0;
	op_optn opcode[] = {{"push", sq_push},
					{"pall", sq_pall},
					{"pint", sq_pint},
					{"pop", sq_pop},
					{"swap", sq_swap},
					{"add", sq_add}};
	/*tokenize content using strtok*/
	op = strtok(content, " \n\t");
	if (strcmp(op, "#") == 0)
	{
		 exit(0);
	}
	arg = strtok(NULL, " \n\t");
	/*check arg*/
	if (!arg)
	{
		flag = 1;
	}
	/*check  if argument is number*/
	for (i = 0; i < strlen(arg); i++)
	{
		if (arg[i] < 48 || arg[i] > 57)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L<%d>: usage: push integer", counter);
		free(content);
		free(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	info.arg = arg;
	/* find the appropriate operation code*/
	while (opcode[j].op != NULL && op)
	{
		if (strcmp(op, opcode[j].op) == 0)
		{
			printf("TEST PRINT");
			opcode[j].func(stack, counter);
		}
		j++;
	}
	if (op && opcode[j].op == NULL)
	{
		fprintf(stderr, "Error: invalid opcode entered\n");


	}

	printf("line %d  :- %s", counter, content);
}
