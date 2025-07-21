#include <stdio.h>

int main() {
  int v = 20;

  int *ptr = &v;

  printf("v => %d ptr => %d", v, *ptr);
}
