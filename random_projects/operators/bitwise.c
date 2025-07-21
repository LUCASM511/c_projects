#include <stdio.h>

int main() {
  int a = 10;
  int b = 7;

  printf("AND: %d", a & b);
  printf("\nOR: %d", a | b);
  printf("\nXOR: %d", a ^ b);
  printf("\nShift Left A: %d", a << 2);
  printf("\nShift Right B: %d", b >> 4);

  return 0;
}
