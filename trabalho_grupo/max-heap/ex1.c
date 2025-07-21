// #include <stdio.h>

void swap(int *, int *);
void max_heapify(int[], int, int);
void build_max_heap(int A[], int tam);
int find_max(int[]);
void print(int[], int);

#include <stdio.h>
#define HEAP_SIZE 7

int main() {
  int array[HEAP_SIZE + 1] = {0, 10, 13, 4, 8, 19, 1, 2};
  int size = HEAP_SIZE;

  printf("Array Original\n");
  print(array, size);

  build_max_heap(array, HEAP_SIZE);

  printf("Array Heapify\n");
  print(array, size);

  int largest = find_max(array);
  printf("Maior elemento: %d\n", largest);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para manter a propriedade de heap
void max_heapify(int A[], int size, int i) {
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest = i;

  if (left <= size && A[left] > A[largest])
    largest = left;

  if (right <= size && A[right] > A[largest])
    largest = right;

  if (largest != i) {
    swap(&A[i], &A[largest]);
    max_heapify(A, size, largest);
  }
}

// Constrói o heap de máximo
void build_max_heap(int A[], int size) {
  // Começa no último nó não-folha (índice size/2) e vai até 1 (raiz)
  for (int i = size / 2; i >= 1; i--)
    max_heapify(A, size, i); // aplica o heap de máximo em cada nó
}

int find_max(int A[]) { return A[1]; }

void print(int A[], int size) {
  for (int i = 1; i <= size; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");
}
