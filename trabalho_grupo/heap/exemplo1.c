#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) ((i) << 1)      // Calcula 2i (filho à esquerda)
#define RIGHT(i) ((i) << 1 | 1) // Calcula 2i + 1 (filho à direita)
#define PARENT(i) ((i) >> 1)    // Calcula i/2 (pai)

typedef struct {
  struct No *no;
} No;

typedef struct;

void swap(int *, int *);
void min_heapify(No *, int);
void build_min_heap(No *, int i);

// void printHeapIndices(int index) {
//   printf("Índice: %d\n", index);
//   printf("Filho à esquerda: %d\n", LEFT(index));
//   printf("Filho à direita: %d\n", RIGHT(index));
//   printf("Pai: %d\n", PARENT(index));
// }

int main() {
  No *no = malloc(sizeof(No *));

  build_min_heap(no, no->data);

  // int index = 3; // Exemplo de índice
  // printHeapIndices(index);
  return 0;
}

int isEmpty() { return -1; }

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void min_heapify(No *no, int i) {

  int left = LEFT(i);
  int right = RIGHT(i);
  int parent = PARENT(i);

  if (no->left >= no->data)
    parent = left;

  if (no->right >= no->parent)
    parent = right;

  if (parent != i) {
    swap(&no->data, &no->parent);
    min_heapify(no, parent);
  }
}

void build_min_heap(No *no, int i) {
  while (isEmpty()) {
    min_heapify(no, i);
  }
}
