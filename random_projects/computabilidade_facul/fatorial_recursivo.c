#include <stdio.h>

long long fatorial_recursivo(int n) {
  if (n <= 1)
    return 1;
  return n * fatorial_recursivo(n - 1);
}

int main() {

  int x = 15;

  int resultado = fatorial_recursivo(x);

  printf("%d", x);

  return 0;
}
