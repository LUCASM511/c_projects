#include <stdio.h>

const char *bmi(int weight, double height);
void tester(int weight, double height, const char *expected);

int main() {
  bmi(50, 1.50);
  bmi(50, 1.80);
  bmi(80, 1.80);
  bmi(90, 1.80);
  bmi(110, 1.80);

  tester(50, 1.80, "Underweight");
  tester(80, 1.80, "Normal");
  tester(90, 1.80, "Overweight");
  tester(110, 1.80, "Obese");
  tester(50, 1.50, "Normal");

  return 0;
}

const char *bmi(int weight, double height) {
  double bmi = weight / (height * height);

  if (bmi <= 18.5)
    return "Underweight";

  if (bmi <= 25.0)
    return "Normal";

  if (bmi <= 30.0)
    return "Overweight";

  return "Obese";
}

void tester(int weight, double height, const char *expected) {
  const char *submited = bmi(weight, height);

  printf("Submitted => %s - Expected => %s\n", submited, expected);
}
