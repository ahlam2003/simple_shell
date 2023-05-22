#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
void fork_exec(char *command, char *args[]);
void tokenize_command(char *command, char *args[]);
int _strcmp(char *s1, char *s2);
void prompt(void);
int _putchar(char c);
#endif /* SHELL_H */
