#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int shell_exit(char **args);

char *read_line(void) {
  char *buffer = NULL;
  size_t size = 0;
  ssize_t chars_read;

  chars_read = getline(&buffer, &size, stdin);

  if (chars_read == -1) {
    perror("getline");
    exit(EXIT_FAILURE);
  }

  return buffer;
}

char **split_line(char *line) {
  char **tokens = NULL;
  char *token;
  int index = 0;

  token = strtok(line, " \t\r\n\a");
  while (token != NULL) {
    tokens = realloc(tokens, sizeof(char *) * (index + 1));
    if (tokens == NULL) {
      perror("realloc");
      exit(EXIT_FAILURE);
    }
    tokens[index] = token;
    index++;

    token = strtok(NULL, " \t\r\n\a");
  }
  tokens = realloc(tokens, sizeof(char *) * (index + 1));
  if (tokens == NULL) {
    perror("realloc");
    exit(EXIT_FAILURE);
  }
  tokens[index] = NULL;
  return tokens;
}

int shell_execute(char **args) {
  if (args[0] == NULL) {
    return 1;
  }
  if (strcmp(args[0], "exit") == 0) {
    return shell_exit(args);
  }
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("fork");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int shell_exit(char **args) {
  if (args[1] != NULL) {
    int status = atoi(args[1]);
    exit(status);
  }
  exit(EXIT_SUCCESS);
}

int main(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("$ ");
    line = read_line();
    args = split_line(line);
    status = shell_execute(args);

    free(line);
    free(args);
  } while (status);

  return EXIT_SUCCESS;
}

