#include <stdio.h>
#define MAX 100

// Declaração das funções
void max_heapify(int[], int, int);
void biuld_max_heap(int[]);
void heap_sort(int[], int);
void swap(int *, int *);
int maximum(int[]);
int extract_maximum(int[], int);
void deletion(int[], int);

typedef struct {
  int tam_heap;
  int heap[MAX];
} Heap;

int main() {
  Heap h;
  int op = 1;
  int valor = 0;

  printf("\nTamanho da heap: ");
  scanf("%d", &h.tam_heap);

  for (int i = 0; i <= h.tam_heap; i++) {
    h.heap[i] = 0;
  }

  while (op) {
    printf("\n[1] ==> Imprimir");
    printf("\n[2] ==> Inserir");
    printf("\n[3] ==> Deletar");
    printf("\n[4] ==> Extrair");
    printf("\n[5] ==> Encontrar");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("Heap\n");
      for (int i = 1; i <= MAX; i++) {
        printf(" %d", h.heap[i]);
      }
      printf("\n");
      break;

    case 2:
      printf("\nValor: ");
      scanf("%d", &valor);
      inserir(valor);
      break;
    }
  }

  printf("Array Original\n");
  for (int i = 1; i <= MAX; i++) {
    printf(" %d", heap[i]);
  }
  printf("\n");

  // chama a função de ordenação
  heap_sort(array, TAMANHO_HEAP);

  printf("Array Ordenado\n");
  for (int i = 1; i <= TAMANHO_HEAP; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  extract_maximum(array, TAMANHO_HEAP);

  printf("Depois de deletar\n");
  for (int i = 1; i <= TAMANHO_HEAP; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  return 0;
}

// Função para trocar dois elementos
void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Função para garantir a propriedade de máximo
void max_heapify(int A[], int tam, int i) {
  int left = 2 * i;      // calcula indice do filho da esquerda
  int right = 2 * i + 1; // calcula indice do filho da direita
  int largest = i;       // inicia com o indice atual

  if (left <= tam && A[left] > A[i]) // verfica o filha da esquerda
    largest = left;

  if (right <= tam && A[right] > A[largest]) // verifica o filho da direita
    largest = right;

  if (largest != i) {         // verifica se o indice não é o atual
    swap(&A[i], &A[largest]); // troca os elementos
    max_heapify(
        A, tam,
        largest); // chamada recursiva para aplicar a função na subárvore
  }
}

// Constrói o heap de máximo
void build_max_heap(int A[], int tam) {
  for (int i = tam / 2; i >= 1;
       i--) { // percorre os nós não folha do heap, último até a raiz
    max_heapify(A, tam, i); // aplica o heap de máximo em cada nó
  }
}

// Função para ordenar o array
void heap_sort(int A[], int tam) {
  build_max_heap(A, tam); // contrói um heap de máximo a partir do array

  // Extrair os elementos do heap um por um
  for (int i = tam; i > 1; i--) {
    swap(&A[1], &A[i]);       // move o maior elemento para o final do array
    max_heapify(A, i - 1, 1); // restaura a propriedade de heap
  }
}

int maximum(int A[]) { return A[1]; }

int extract_maximum(int A[], int tam) {
  if (tam < 1) {
    printf("\nA heap está vazia");
    return -1;
  }

  int largest = A[1];
  A[1] = A[tam - 1];
  --tam;

  deletion(A, tam);

  return largest;
}

void deletion(int A[], int tam) {
  swap(&A[1], &A[tam - 1]);
  max_heapify(A, tam, 1);
}

void insert(int valor) { heap }
