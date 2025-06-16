#include <stdio.h>

void merge(int[], int, int, int);
void merge_sort(int[], int, int);
void print_array(int[], int);

int main() {
  int arr[] = {10, 3, 4, 1, 6, 5, 9, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\nNot sorted array\n");
  print_array(arr, n);

  merge_sort(arr, 0, n - 1);

  printf("\nSorted array\n");
  print_array(arr, n);

  return 0;
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void merge_sort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1; // length of A[l:m]
  int n2 = r - m;     // length of A[m+1:r]

  int L[n1], R[n2]; // create arrays with respective lengths nl and nr
                    // temporary arrays to save A[l:m] and A[m+1:r] values

  for (i = 0; i < n1; i++) // copy A[l:m] into L[]
    L[i] = arr[l + i];
  for (j = 0; i < n2; i++) // copy A[m+1:r] into R[]
    R[j] = arr[m + 1 + j];

  i = 0; // i/j indexes the smallest remaining element in L/R
  j = 0;
  k = l; // k indexes the location in A to fill

  // As long as each of the arrays L and R contains an unmerged element,
  // copy the smallest unmerged element back into A[l:r]
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Having gone through one of L and R entirely, copy the
  // remainder of the other to the end of A[l:r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
