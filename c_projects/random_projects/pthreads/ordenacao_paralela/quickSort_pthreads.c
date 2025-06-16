#include <pthread.h>
#include <stdio.h>

#define N 10 // tamanho do array
#define NUM_THREADS 4 // números de threads

// array a ser ordenado
int array[N] = {3, 1, 2, 9, 8, 4, 6, 7, 5};

// Declara as funcoes acima da main
void swap(int *, int *);
int particiona(int, int);
void *quickSort(void*);

int main() {
  pthread_t threads[NUM_THREADS]; // declaração de um array de threads
  int particao[] = {0, N - 1}; // declaração de um array para a função de ordenação

  // imprimi o array não ordenado
  printf("Array não ordenado\n");
  for (int i= 0; i < N; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  pthread_create(&threads[0], NULL, quickSort, (void *)particao); // cria a thread que chama a função quickSort

  pthread_join(threads[0], NULL); // aguarda o termínio da thread criada

  // imprimi o array ordenado
  printf("Array ordenado\n");
  for (int i= 0; i < N; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");

  return 0;
}

// muda os valore de posiçao no array
void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

// função para particionar o array em array menores
int particiona(int ini, int fim) {

  // calcula a mediana de três para escontrar o valor do pivo
  int pivo = (array[ini] + array[fim] + array[(ini + fim) / 2]) / 3;

  while (ini < fim) {
    // percorre o array até que ini seja maior/igual a fim && array[ini] seja menor/igual que pivo
    while (ini < fim && array[ini] <= pivo) 
      ini++;
    // percorre o array até que ini seja maior/igual a fim && array[fim] seja maior que pivo
    while (ini < fim && array[fim] > pivo) 
      fim--;

    if (ini < fim)
      swap(&array[ini], &array[fim]); // chama a função para a troca de posições dos valores no array
  }
  return ini;
}

// ordena os valores no array
void *quickSort(void *args){
  int *particao = (int *) args; // converte o ponteiro em um ponteiro para um array de inteiros

  // obtém o elemento do array
  int ini = particao[0];
  int fim = particao[1]; 

  if (ini < fim) {
    int pos = particiona(ini, fim); // chama a função para o obter o indíce da posição

    pthread_t threads[2]; // array de duas threads

    // arrays para a chamada recursiva do quicksort
    int particao1[] = {ini, pos - 1}; 
    int particao2[] = {pos + 1, fim};

    // criaçaõ da threads para chamar a função quickSort
    pthread_create(&threads[0], NULL, quickSort, (void*)particao1);
    pthread_create(&threads[1], NULL, quickSort, (void*)particao2);

    // espera o termínio das threads
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
  }

  pthread_exit(NULL); // termina a thread atual
}
