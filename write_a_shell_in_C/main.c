#include <stdio.h>
#include <stdlib.h>

void lsh_loop();

int main(int argc, char **argv) {
  // Load config files, if any

  // Run command loop
  lsh_loop();

  // Perform any shudown/cleanup

  return EXIT_SUCCESS;
}

void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line(); // Read the command from standard input.
    args = lsh_split_line(line); // Separate the command string into a program and arguments.
    status = lsh_execute(args); // Run the parsed command.

    free(line);
    free(args);
  }while (status);
}
