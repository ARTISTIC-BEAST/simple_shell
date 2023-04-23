#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LEN];
    char* args[MAX_ARGS];
    int status;

    while (1) {
        // Print the shell prompt and read the user's input
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Remove the trailing newline character from the input
        cmd[strcspn(cmd, "\n")] = '\0';

        // Split the input into separate arguments
        int i = 0;
        args[i] = strtok(cmd, " ");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            args[++i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Check if any argument contains a variable reference
        for (i = 0; args[i] != NULL; i++) {
            char* var_ref = strchr(args[i], '$');
            if (var_ref != NULL) {
                // Replace the variable reference with its value
                if (strncmp(var_ref, "$?", 2) == 0) {
                    // Replace $? with the exit status of the last command executed
                    sprintf(var_ref, "%d", WEXITSTATUS(status));
                } else if (strncmp(var_ref, "$$", 2) == 0) {
                    // Replace $$ with the PID of the current shell
                    sprintf(var_ref, "%d", getpid());
                }
            }
        }

        // Execute the command
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror(args[0]);
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            wait(&status);
        }
    }

    return 0;
}
