#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shell* 
createShell(void)
{
  struct shell* shell = (struct shell*)malloc(sizeof(struct shell));

  shell->init = init; 
  shell->run = run;
  
  return shell;
}

char** process(char* input)
{
  int i = 0;
  char** tokens = (char**)malloc(sizeof(char*) * 100);
  char* token;  

  token = strtok(input, " ");

  while (token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, " ");
  }

  tokens[i] = NULL;
  i = 0;
  
  return tokens;
}

char* 
getInput(void)
{
  char* buffer = (char*)malloc(sizeof(char) * STD_BUFFER_SIZE);
  read(STD_I, buffer, sizeof(char) *  STD_BUFFER_SIZE);

  return buffer;
}

int
printPrompt(void)
{
  write(STD_O, "$ ", 2);
  
  return EXIT_SUCCESS;
}

int 
init(void)
{
  setvbuf(stdout, NULL, NO_BUFFERED, 0);

  return EXIT_SUCCESS;
}

int 
run(void)
{
  printPrompt();

  int i = 0;
  char* input = getInput();
  char** tokens = process(input);    

  while (tokens[i] != NULL) {
    printf("%s\n", tokens[i]);
    i++;
  }

  free(input);

  return EXIT_SUCCESS;
}

int
execCommand(void)
{
  return EXIT_SUCCESS;
}
