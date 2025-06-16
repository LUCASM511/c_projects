#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dados;
  struct Test *t;
} Test;

Test ini();

int main() {
  int *ptr = (int *)malloc(5 * sizeof(int *)); // 5 * 4 (int == 4 bits) = 20

  ini();

  return 0;
}

Test ini() {
  Test *t = (Test *)malloc(sizeof(Test));

  if (t == NULL) {
    printf("Memoria nao alocada");
    exit(1);
  }

  if (t)
    printf("Memoria alocada");

  return *t;
}
