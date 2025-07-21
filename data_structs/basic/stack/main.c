#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dados;
  struct No *next;
} No;

// bool stack_empty(No *);
int *create_stack();
void pop(int *, int);
No *isFull(int *);

int main() {
  No *no;

  // switch case
  // if stack_empty
  //
  //  ini_stack();

  create_stack();
  pop((int *)no, 5);
  return 0;
}

int isEmpty(int top) { return (top == -1); }
// No *isFull(No *top) { return (top == top->next - 1); };

int *create_stack() {
  int *no = (int *)malloc(sizeof(int));
  return no;
}

void pop(int *stack, int valor) {

  if (isFull(stack)) {
    printf("Full stack");
    return;
  }

  stack[valor] += valor;
}
