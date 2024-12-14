#include "core.h"
#include <stdio.h>

struct shell* 
createShell(void)
{
  struct shell* shell = (struct shell*)malloc(sizeof(struct shell));

  shell->init = init; 
  shell->run = run;
  
  return shell;
}

char* process(char* input)
{

  return input;
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

  char* input = getInput();
  process(input);  

  free(input);

  return EXIT_SUCCESS;
}

int
execCommand(void)
{
  return EXIT_SUCCESS;
}
