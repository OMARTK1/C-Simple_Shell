#include "shell.h"

/**
 *  * display_prompt_cmd - function that displays a prompt command line
 */
void display_prompt_cmd(void)
{
	printf("sh@beta$ ");
}

/**
 *  * readin_inputs - function that reads from user the line of inputs
 *   *
 *    * Return: allocats dynamically the inputs of user as a string
 */
char *readin_inputs(void)
{
	char *inputs = NULL;
	size_t in_size = 0;
	ssize_t r_buff = getline(&inputs, &in_size, stdin);

	if (r_buff == -1)
	{
		if (feof(stdin))
		{
			free(inputs);

			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	return (inputs);
}

