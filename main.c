#include "shell.h"
/**
 * main - Entry point for the simple shell program `hsh`
 * Return: the exit status of the shell `hsh`
 */
int main(void)
{
	char *inputs;
	char **arrgs;
	int mark_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt_cmd();

		inputs = readin_inputs();

		if (inputs == NULL)
			break;

		arrgs = tokenizer_inputs(inputs);

		if (arrgs[0] != NULL)
		{
			if (strcmp(arrgs[0], "exit") == 0)
			{
				free(arrgs);
				free(inputs);
				exit(mark_status);
			}

			mark_status = executer_command(arrgs);
		}
		free(inputs);
		free(arrgs);
		arrgs = NULL;
	}
	return (0);
}

