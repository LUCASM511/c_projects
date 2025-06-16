#include <math.h> // Para a função pow
#include <stdio.h>

#define TAMANHO_HEAP 7 // Define o tamanho do heap

void max_heapify(int[], int, int);
void build_max_heap(int[], int);
void heap_sort(int[], int);
void swap(int *, int *);
void print_tree(int[], int); // Declaração da função para imprimir a árvore

int main() {
  // Declara um array de tamanho TAMANHO_HEAP + 1 para permitir indexação a
  // partir de 1
  int array[TAMANHO_HEAP + 1] = {
      0,  10, 2,  4,
      30, 34, 50, 67}; // O primeiro elemento (índice 0) é um valor dummy

  // Exibe o array original
  printf("Original array:");
  for (int i = 1; i <= TAMANHO_HEAP; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  // Imprime a estrutura do heap antes da ordenação
  printf("Heap structure before sorting:\n");
  print_tree(array, TAMANHO_HEAP);

  // Chama a função de ordenação heap sort
  heap_sort(array, TAMANHO_HEAP);

  // Exibe o array ordenado
  printf("Sorted array:");
  for (int i = 1; i <= TAMANHO_HEAP; i++) {
    printf(" %d", array[i]); // Imprime cada elemento do array ordenado
  }
  printf("\n");

  // Imprime a estrutura do heap após a ordenação
  printf("Heap structure after sorting:\n");
  print_tree(array, TAMANHO_HEAP);

  return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}

// Função para trocar dois elementos
void swap(int *x, int *y) {
  int temp = *x; // Armazena o valor de x em uma variável temporária
  *x = *y;       // Atribui o valor de y a x
  *y = temp;     // Atribui o valor armazenado temporariamente a y
}

// Função para garantir a propriedade de max-heap
void max_heapify(int A[], int tam, int i) {
  int left = 2 * i;      // Calcula o índice do filho à esquerda
  int right = 2 * i + 1; // Calcula o índice do filho à direita
  int largest = i;       // Inicializa o maior como o índice atual

  // Se o filho à esquerda for maior que o elemento atual
  if (left <= tam && A[left] > A[largest])
    largest = left; // Atualiza o maior para o filho à esquerda

  // Se o filho à direita for maior que o maior atual
  if (right <= tam && A[right] > A[largest])
    largest = right; // Atualiza o maior para o filho à direita

  // Se o maior não for o índice atual, faz a troca
  if (largest != i) {
    swap(&A[i], &A[largest]); // Troca os elementos
    max_heapify(
        A, tam,
        largest); // Recursivamente aplica max_heapify no subárvore afetado
  }
}

// Função para construir um max-heap a partir de um array
void build_max_heap(int A[], int tam) {
  // Percorre os nós não-folha do heap, começando do último até a raiz
  for (int i = tam / 2; i >= 1; i--) {
    max_heapify(A, tam, i); // Aplica max_heapify em cada nó
  }
}

// Função para ordenar o array usando heap sort
void heap_sort(int A[], int tam) {
  build_max_heap(A, tam); // Constrói um max-heap a partir do array

  // Extrai elementos do heap um por um
  for (int i = tam; i > 1; i--) {
    swap(&A[1], &A[i]); // Move o maior elemento (raiz) para o final do array
    max_heapify(A, i - 1,
                1); // Restaura a propriedade de max-heap na parte restante
  }
}

// Função para imprimir a estrutura do heap em formato de árvore
void print_tree(int A[], int tam) {
  int levels = log2(tam) + 1; // Calcula o número de níveis na árvore

  for (int i = 0; i < levels; i++) {
    int num_elements = pow(2, i);    // Número de elementos no nível atual
    int start_index = pow(2, i) - 1; // Índice inicial para o nível atual

    // Imprime os elementos do nível atual
    for (int j = 0; j < num_elements && start_index + j < tam + 1; j++) {
      printf("%d ", A[start_index + j]);
    }
    printf("\n"); // Nova linha após cada nível
  }
}
