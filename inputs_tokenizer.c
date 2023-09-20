#include "shell.h"

/**
 * tokenizer_inputs - function that tokenizes a string
 *						by spliting it into array of tokens
 * @inputs: that string to be tokenized
 *
 * Return: array of tokens
 */
char **tokenizer_inputs(char *inputs)
{
	int item_qty = 0;
	char *item = strtok(inputs, " \t\n");
	char **arr_tok = (char **)malloc(MAX_ARGS_SIZE * sizeof(char *));

	if (!arr_tok)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (item != NULL)
	{
		arr_tok[item_qty++] = item;
		item = strtok(NULL, " \t\n");
	}

	free(item);
	item = NULL;
	arr_tok[item_qty] = NULL;

	return (arr_tok);
}

