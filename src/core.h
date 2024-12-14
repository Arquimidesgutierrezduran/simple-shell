#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STD_I 0
#define STD_O 1
#define STD_BUFFER_SIZE 1024

#define NO_BUFFERED _IONBF

struct shell
{
  int (*init)(void);
  int (*run)(void);
};

struct shell* createShell(void);

int init(void);
int run(void);
int execCommand(void);
int printPrompt(void);
char* getInput(void);
char* process(char* input);
