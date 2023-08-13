#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

void exec(char **buff);

void frees(char *str1, char *str2, char *str3);

void free_buff(char **buff);

char *_getenv(void);

char **create_buff(char *input);

int child_process(char *str, char **bff);

int status(char **buff);

char *_which(char **buff, char *path);

#endif