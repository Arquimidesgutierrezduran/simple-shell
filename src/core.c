#include "core.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

struct shell *createShell(void) {
  struct shell *shell = (struct shell *)malloc(sizeof(struct shell));

  shell->init = init;
  shell->run = run;

  return shell;
}

char **process(char *input) {
  int i = 0;
  char **tokens = (char **)malloc(sizeof(char *) * 100);
  char *token;

  token = strtok(input, " ");

  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, " ");
  }

  int size = strlen(tokens[i - 1]);

  tokens[i - 1][size - 1] = '\0';
  tokens[i] = NULL;
  i = 0;

  return tokens;
}

char *getInput(void) {
  char *buffer = (char *)malloc(sizeof(char) * STD_BUFFER_SIZE);
  read(STD_I, buffer, sizeof(char) * STD_BUFFER_SIZE);

  return buffer;
}

int printPrompt(void) {
  write(STD_O, "$ ", 2);

  return EXIT_SUCCESS;
}

int init(void) {
  setvbuf(stdout, NULL, NO_BUFFERED, 0);

  return EXIT_SUCCESS;
}

int run(void) {
  while (1) {
    printPrompt();

    int i = 0;
    char *input = getInput();
  
    if (input[0] ==  'e') {
      if (input[1] == 'x') {
        if (input[2] == 'i') {
          if (input[3] == 't') {
            break; 
          }
        } 
      }
    }

    char **tokens = process(input);
    int status = execCommand(tokens);

    free(input);
  }

  return EXIT_SUCCESS;
}

int execCommand(char **tokens) {
  int status;
  char *path = malloc(sizeof(char) * 100);
  path[0] = '/';
  path[1] = 'u';
  path[2] = 's';
  path[3] = 'r';
  path[4] = '/';
  path[5] = 'b';
  path[6] = 'i';
  path[7] = 'n';
  path[8] = '/';
  path = strcat(path, tokens[0]);

  if (fork() != 0) {
    waitpid(-1, &status, 0);
  } else {
    execve(path, tokens, 0);
  }

  if (status != 0) {
    printf("%d\n", -1);
  }

  return EXIT_SUCCESS;
}
