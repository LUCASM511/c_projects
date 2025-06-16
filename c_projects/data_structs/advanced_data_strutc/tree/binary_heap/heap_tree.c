#include <stdio.h>
#define TAMANHO_HEAP 6 // Define o tamanho do heap

// Declaração das funções
void max_heapify(int[], int, int);
void build_max_heap(int[], int);
void heap_sort(int[], int);
void swap(int *, int *);
int find_max(int[]);
int extract_max(int[], int *);
void deletion(int[], int *);
int insert(int[], int *, int);
int increase_key(int[], int, int);
void print(int[], int);

int main() {
  // int array[TAMANHO_HEAP + 1] = {0,  10, 2,  4, 30, 34, 50, 67}; // inicia no
  // indice 1
  int array[TAMANHO_HEAP + 1] = {0, 5, 15, 1, 20, 3, 6}; // inicia no indice 1

  // Imprimi o array original
  printf("\nArray Original");
  print(array, TAMANHO_HEAP);

  build_max_heap(array,
                 TAMANHO_HEAP); // manter a propriedade de máximo

  // Imprimi o heap de máximo
  printf("\nHeapify");
  print(array, TAMANHO_HEAP);

  heap_sort(array, TAMANHO_HEAP); // ordena o array

  // Imprimi o array ordenado
  printf("\nArray Ordenado");
  print(array, TAMANHO_HEAP);

  build_max_heap(array,
                 TAMANHO_HEAP); // manter a propriedade de máximo

  // Retornando e deletando nó raiz
  int novoTam = TAMANHO_HEAP;
  int max = extract_max(array, &novoTam); // função de extrair
  if (max != -1)
    printf("\nMáximo extraido: %d", max);

  printf("\nDepois de deletar");
  print(array, novoTam);

  // Inserindo um valor ao final
  int valor_inserido = 30;
  printf("\nInserindo o valor: %d", valor_inserido);
  insert(array, &novoTam, valor_inserido); // função de inserir

  printf("\nDepois de inserir");
  print(array, novoTam);

  heap_sort(array, novoTam); // ordenando o array

  // Imprimi o array ordenado
  printf("\nArray Ordenado");
  print(array, novoTam);

  build_max_heap(array,
                 novoTam); // manter a propriedade de máximo

  increase_key(array, 2, 50); // aumentar o valor de elemento
  printf("\nDepois de chave aumentada");
  print(array, novoTam);

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

// Função para construir o heap de máximo
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

// Função que retorna o maior valor
int find_max(int A[]) { return A[1]; }

// Função para extrair e deletar o nó raiz (maior elemento)
int extract_max(int A[], int *tam) {
  if (*tam < 1) {
    printf("\nA heap está vazia");
    return -1;
  }

  int largest = A[1];
  A[1] = A[*tam];          // mover o último elemento para o topo
  (*tam)--;                // decrementa o tamanho da heap
  max_heapify(A, *tam, 1); // restaura a propriedade de max-heap

  return largest;
}

// Função para deletar o nó raiz (maior valor)
void deletion(int A[], int *tam) {
  if (*tam > 0) {
    swap(&A[1], &A[*tam]);
    (*tam)--;
    max_heapify(A, *tam, 1);
  }
}

// Função para inserir um valor ao final
int insert(int A[], int *tam, int key) {
  if (*tam >= TAMANHO_HEAP) {
    printf("\nHeap está cheio");
    return -1;
  }

  (*tam)++;      // aumenta o tamanho do heap
  A[*tam] = key; // coloca o novo elemento na última posição

  // Up-heap para restaurar a propriedade de heap máximo
  int i = *tam;
  // Enquanto o nó não for a raiz e o valor for maior que o pai
  while (i > 1 && A[i] > A[i / 2]) {
    swap(&A[i], &A[i / 2]); // troca o pai
    i = i / 2;              // move para o índice do pai
  }

  return 0;
}

// Função que aumenta o valor de um elemento
int increase_key(int A[], int i, int key) {
  // Verifica o valor da chave
  if (key < A[i]) {
    printf("\nNova chave  %d é menor que a atual %d", key, A[i]);
    return -1;
  }

  A[i] = key; // atualiza o valor da chave

  // Restaura a propriedade de heap de máximo
  while (i > 1 && A[i / 2] < A[i]) {
    swap(&A[i], &A[i / 2]); // troca o nó com o pai
    i = i / 2;              // muda o índice para o índice pai
  }

  return 0; // indica que o valor foi aumentado com sucesso
}

// Função de imprimir
void print(int A[], int tam) {
  printf("\n");
  for (int i = 1; i <= tam; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");
}
