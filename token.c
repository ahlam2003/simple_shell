#include "shell.h"
void tokenize_command(char *command, char *args[]) {
    char *token;
    int arg_count = 0;
    token = strtok(command, " ");
    while (token != NULL && arg_count < MAX_ARGUMENTS - 1) {
        args[arg_count] = token;
        token = strtok(NULL, " ");
        arg_count++;
    }
    args[arg_count] = NULL;
}
