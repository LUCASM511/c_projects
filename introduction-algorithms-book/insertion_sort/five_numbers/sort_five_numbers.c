#include <stdio.h>

int main() {
  int array[] = {5, 2, 4, 6, 1, 3};
  /* Calcula o número de elementos no array dividindo
    o tamanho total do array pelo tamanho de um elemento.*/
  int n = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < n; i++) {
    // Only the first number (5) don't change your position

    int key = array[i];
    // On by one move the position to the right
    // util it finds the proper position
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      // On by one move the position to the right
      // util it finds the proper position
      j = j - 1;
    }
    // At this point
    // it insert the value of A[i]
    array[j + 1] = key;
  }
  // Print sorted array
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
