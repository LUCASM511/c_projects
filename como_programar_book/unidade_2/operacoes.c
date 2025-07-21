#include <stdio.h>

int main() {
  int num = 0;
  int num2 = 0;

  printf("Enter with two numbers: ");
  scanf("%d %d", &num, &num2);

  int result = num + num2;
  printf("Sum: %d\n", result);

  result = num - num2;
  printf("Sub: %d\n", result);

  result = num * num2;
  printf("Multiplication: %d\n", result);

  result = num / num2;
  printf("Division: %d\n", result);

  result = num % num2;
  printf("Mod: %d\n", result);
}
