#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS_SIZE 1024

void display_prompt_cmd(void);
char *readin_inputs(void);
char **tokenizer_inputs(char *inputs);
int executer_command(char **arrgs);


#endif /* SHELL_H */
