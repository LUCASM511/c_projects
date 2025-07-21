#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_500 500
#define SIZE_1000 1000
#define SIZE_10000 10000

void max_min_1(int v[], int n, int *max, int *min) {

  for (int i = 1; i < n; i++) {
    if (v[i] > *max)
      *max = v[i];
    if (v[i] < *min)
      *min = v[i];
  }
}

void imprimir_vetor(int *vetor, int tamanho, const char *nome) {
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % tamanho;
  }

  int max = vetor[0];
  int min = vetor[0];
  max_min_1(vetor, tamanho, &max, &min);
  printf("\n%s -> Max: %d Min: %d", nome, max, min);
}

int main() {
  srand(time(NULL));

  int v1[SIZE_500];
  int v2[SIZE_1000];
  int v3[SIZE_10000];

  imprimir_vetor(v1, SIZE_500, "Vetor 500");
  imprimir_vetor(v2, SIZE_1000, "Vetor 1000");
  imprimir_vetor(v3, SIZE_10000, "Vetor 10000");

  return 0;
}
