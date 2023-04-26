#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ALIASES 100
#define MAX_ALIAS_NAME_LENGTH 100
#define MAX_ALIAS_VALUE_LENGTH 100

/**
 * struct alias - struct name
 * Description: contains struct members
 * @name: member
 * @value: member
 */

struct alias
{
        char name[MAX_ALIAS_NAME_LENGTH];
        char value[MAX_ALIAS_VALUE_LENGTH];
};

struct alias aliases[MAX_ALIASES];

void free_args(char **args);
int parse_line(char *line, char **args);
int execute_line(char **args);
int execute_command(char **args, int bg);
void print_aliases(void);
void print_alias(char *name);
void add_alias(char *name, char *value);
void process_command(char *command);
int env_builtin(void);
/*int cd_builtin(char **args, char **env, status_t *status);*/
int execute(char **args, char **env);
int setenv_builtin(char **args);
int unsetenv_builtin(char **args);
char *_getline(void);
int run_command(char *cmd);
void exec_cmd(char **args);
int _env(char **args, char **env);
int shell_exit(char **args);
char *read_line(void);
char **split_line(char *line);
int shell_execute(char **args);
int shell_execute(char **args);
int shell_exit(char **args);
char **split_string(char *line, const char *delim);


#endif
