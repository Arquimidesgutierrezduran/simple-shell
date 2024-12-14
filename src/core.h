#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define STD_I 0
#define STD_O 1
#define STD_BUFFER_SIZE 1024

#define NO_BUFFERED _IONBF

struct shell {
  int (*init)(void);
  int (*run)(void);

  char **paths;
};

struct shell *createShell(void);

int init(void);
int run(void);
int execCommand(char **tokens);
int printPrompt(void);
char *getInput(void);
char **process(char *input);
