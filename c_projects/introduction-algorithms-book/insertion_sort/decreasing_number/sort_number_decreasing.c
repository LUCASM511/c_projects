#include <stdio.h>

int main() {
  int array[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < n; i++) {
    int key = array[i]; // take each value from array
    int j = i - 1;      // take the value from the loop for
    // Move elements of arr[0.. i-1]
    // than are less tha key
    while (j >= 0 && array[j] < key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
