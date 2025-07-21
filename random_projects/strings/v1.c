#include <stdio.h>

int main() {

  char full_name[20];
  char c;

  printf("Full name => ");
  fgets(full_name, 20, stdin);

  fputs(full_name, stdout);

  return 0;
}
