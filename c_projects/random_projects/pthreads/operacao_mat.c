#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <threads.h>
#include <time.h>


void *soma(void *args) {
	int *num = (int*) args;
	int resultado = num[0] + num[1];

	printf("\nSoma => %d", resultado);
	pthread_exit(NULL);
}

void *subtracao(void *args) {
	int *num = (int*) args;
	int resultado = num[0] - num[1];

	printf("\nSubtracao => %d", resultado);
	pthread_exit(NULL);
}

void *multiplicacao(void *args) {
	int *num = (int *) args;
	int resultado = num[0] * num[1];

	printf("\nMultiplicacao => %d", resultado);
	pthread_exit(NULL);
}

void *divisao(void *args) {
	int *num = (int *) args;
	int resultado = num[0] / num[1];

	printf("\nDivisao => %d", resultado);
	pthread_exit(NULL);
}

int main() {

	pthread_t thread_soma;
	pthread_t thread_subtracao;
	pthread_t thread_multiplicacao;
	pthread_t thread_divisao;
	int nums[2] = {10, 5};
	
	pthread_create(&thread_soma, NULL, soma, (void *)nums);
	pthread_create(&thread_subtracao, NULL, subtracao, (void*) nums);
	pthread_create(&thread_multiplicacao, NULL, multiplicacao, (void*) nums);
	pthread_create(&thread_subtracao, NULL, divisao, (void*) nums);

	pthread_join(thread_soma, NULL);
	pthread_join(thread_subtracao, NULL);

	return 0;
}
