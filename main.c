#include "shell.h"
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	int status;
	while (1)
	{
		prompt();
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");  /* Handle end of file (Ctrl+D)*/
			break;
		}
		size_t command_length = strlen(command);
		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';  /*Remove the newline character */
		}
		if (_strcmp(command, "exit") == 0)
		{  /* Check for "exit" command*/
			break;  /* Exit the shell*/
		}
		if (_strcmp(command, "") == 0)
		{  /* Handle empty input*/
			continue;
		}
		char *args[MAX_ARGUMENTS];
		tokenize_command(command, args);
		fork_exec(args[0], args);
	}
	return (0);
}
