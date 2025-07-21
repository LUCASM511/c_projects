#include <stdio.h>

int fn_sum(int array[], int n) {
  int sum = 0;
  int i = 1;

  while (i <= n) {
    sum = sum + array[i];
    i = i + 1;
  }
  return sum;
}

int main() {
  int array[] = {1, 3, 7, 9};
  int n = sizeof(array) / sizeof(array[0]);

  fn_sum(array, n);

  for (int i = 1; i < array[n]; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
