#include "shell.h"
void fork_exec(char *command, char *args[]) {
    pid_t pid;
    int status;
    pid = fork();  // Create a new process
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execvp(command, args);
        // If the above execvp fails, print an error message
        perror(command);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}




