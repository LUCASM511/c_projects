#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_500 500
#define SIZE_1000 1000
#define SIZE_10000 10000

void max_min_3(int v[], int n, int *max, int *min) {
  int i;

  if (n % 2 == 0) {
    if (v[0] > v[1]) {
      *max = v[0];
      *min = v[1];
    } else {
      *max = v[1];
      *min = v[0];
    }
    i = 2;
  } else {
    *max = *min = v[0];
    i = 1;
  }

  while (i < n - 1) {
    if (v[i] > v[i + 1]) {
      if (v[i] > *max)
        *max = v[i];
      if (v[i + 1] < *min)
        *min = v[i + 1];
    } else {
      if (v[i + 1] > *max)
        *max = v[i + 1];
      if (v[i] < *min)
        *min = v[i];
    }
    i += 2;
  }
}

void processar_vetor(int *vetor, int tamanho, const char *nome) {
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand() % tamanho;
  }

  int max, min;
  max_min_3(vetor, tamanho, &max, &min);
  printf("\n%s -> Max: %d Min: %d", nome, max, min);
}

int main() {
  srand(time(NULL));

  int v1[SIZE_500];
  int v2[SIZE_1000];
  int v3[SIZE_10000];

  processar_vetor(v1, SIZE_500, "Vetor 500");
  processar_vetor(v2, SIZE_1000, "Vetor 1000");
  processar_vetor(v3, SIZE_10000, "Vetor 10000");

  return 0;
}
