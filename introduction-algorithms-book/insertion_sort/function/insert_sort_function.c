#include <stdio.h>

void fn_insertion(int arr[], int n) {
  int i, key, j;

  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    // Move elements of array[0.. i-1]
    // that greater than key
    // to one positon ahead of
    // their current positon
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// printf sorted array
void print_array(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int array[] = {2, 1, 3, 5, 6};
  int n = sizeof(array) / sizeof(array[0]);

  fn_insertion(array, n);
  print_array(array, n);

  return 0;
}
