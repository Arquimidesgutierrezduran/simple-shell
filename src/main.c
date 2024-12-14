#include "core.h"

int
main(int argc, char *argv[])
{
  struct shell* shell = createShell();

  if (shell->init() != EXIT_SUCCESS) {
    fprintf(stderr, "ERR: Lo siento, no se ha podido inicializar la shell\n");
    return EXIT_FAILURE;
  }

  if (shell->run() != EXIT_SUCCESS) {
    fprintf(stderr, "ERR: Lo siento la shell ha terminado con un error\n");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
