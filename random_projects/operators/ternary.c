#include <stdio.h>

int main() {
  int result = 0;

  printf("Result => ");
  scanf("%d", &result);

  (result >= 600) ? printf("Congratulations")
                  : printf("Try another time later! :(");

  return 0;
}
