#include <stdio.h>

int main() {
  int array[50];
  int num = 0;

  printf("Size of array: ");
  scanf("%d", &num);

  for (int i = 0; i < num; i++)
    array[i] = 0;

  printf("Enter with elements of array: ");

  for (int i = 0; i < num; i++)
    scanf(" %d", &array[i]);

  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  printf("\nSorted Array");

  for (int i = 0; i < num; i++)
    printf(" %d", array[i]);

  return 0;
}
