#include "shell.h"

/**
 * executer_command - function that executes command with arguments
 *						in a child process
 * @arrgs: array of strings contains the command and arguments
 *
 * Return: the exit status of the executed command
 */
int executer_command(char **arrgs)
{
	pid_t pid;
	int mark_status;

	if
		((pid = fork()) == -1)
		{
			perror("fork");
			return (-1);
		}

	if (pid == 0)
	{
		if (execvp(arrgs[0], arrgs) == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			if (waitpid(pid, &mark_status, 0) == -1)
			{
				perror("waitpid");
				return (-1);
			}
		} while (!WIFEXITED(mark_status) && !WIFSIGNALED(mark_status));

		if (WIFEXITED(mark_status))
		{
			return (WEXITSTATUS(mark_status));
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

