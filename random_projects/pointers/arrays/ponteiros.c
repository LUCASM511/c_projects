#include <stdio.h>

int main() {
  int array[100];
  int size = 0;
  int input = 0;

  printf("Size of array: ");
  scanf(" %d", &size);

  for (int i = 0; i < size; i++) {
    array[i] = 0;
  }

  return 0;
}
