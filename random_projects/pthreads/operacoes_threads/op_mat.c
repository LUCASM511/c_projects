#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100

int nums[ARRAY_SIZE];
int resultado[NUM_THREADS];

void *soma(void *thread_id) {
  int *id = (int *)thread_id;
  int ini = *id * (ARRAY_SIZE / NUM_THREADS);
  int fim = (*id + 1) * (ARRAY_SIZE / NUM_THREADS);

  for (int i = ini; i < fim; i++) {
    resultado[*id] += nums[i];
  }

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < ARRAY_SIZE; i++) {
    nums[i] = i + 1;
  }

  int thread_ids[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    resultado[i] = 0;
    thread_ids[i] = i;
    pthread_create(&threads[i], NULL, soma, (void *)threads[i]);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  int resultado_final = 0;
  for (int i = 0; i < NUM_THREADS; i++) {
    resultado_final += resultado[i];
  }

  printf("Soma final => %d ", resultado_final);

  return 0;
}
