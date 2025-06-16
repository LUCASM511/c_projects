#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int *, int, int);

int main() {
  int flowerbed[] = {0, 0, 1, 0, 1, 0, 1};

  canPlaceFlowers(flowerbed, 5, 1);

  return 0;
}

bool canPlaceFlowers(int *flowerbed, int flowerSize, int n) {
  bool state = false;

  for (int i = 0; i < flowerSize - 1; i++) {
    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 &&
        flowerbed[i] == '\0') {
      flowerbed[i] = 1;
      state = true;
    } else {
      state = false;
    }

    flowerbed[i] = flowerbed[i + 1];
  }

  return printf("%s", state ? "true" : "false");
}
