#include <stdio.h>

// Estrutura para armazenar o menor (min) e o maior (max) valor
typedef struct {
  int min;
  int max;
} Min_Max;

// Função recursiva que encontra o menor e o maior elemento de um subvetor
Min_Max find_min_max(int arr[], int left, int right) {
  Min_Max resultado, left_res, right_res;

  // Apenas um elemento no subvetor
  if (left == right) {
    resultado.min = resultado.max = arr[left]; // Tanto o min quanto o max
    return resultado;
  }

  // Dois elementos no subvetor
  if (right == left + 1) {
    // Compara os dois elementos para definir min e max
    if (arr[left] < arr[right]) {
      resultado.min = arr[left];
      resultado.max = arr[right];
    } else {
      resultado.min = arr[right];
      resultado.max = arr[left];
    }
    return resultado;
  }

  // Divide o vetor ao meio
  int mid = (left + right) / 2;

  // Função recursivamente para a metade esquerda
  left_res = find_min_max(arr, left, mid);

  // Função recursivamente para a metade direita
  right_res = find_min_max(arr, mid + 1, right);

  // Combina os resultados
  // Pega o menor entre os dois mins e o maior entre os dois maxs
  resultado.min = (left_res.min < right_res.min) ? left_res.min : right_res.min;
  resultado.max = (left_res.max > right_res.max) ? left_res.max : right_res.max;

  return resultado; // Retorna o resultado combinado
}

int main() {
  int arr[] = {23, 54, 12, 67, 2, 88, 19};

  // Calcula o tamanho do vetor
  int n = sizeof(arr) / sizeof(arr[0]);

  // Função para encontrar min e max no vetor completo
  Min_Max res = find_min_max(arr, 0, n - 1);

  printf("Menor elemento => %d\n", res.min);
  printf("Maior elemento => %d\n", res.max);

  return 0;
}
