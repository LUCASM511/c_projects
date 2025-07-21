#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char string[] = "C Programming Language";
  int array[] = {};
  int i = 0;
  char c;

  for (int i = 0; i <= strlen(string); i++)
    if (string[i] != '\n')
      array[i] = atoi(string);

  while ((c = getchar()) != EOF)
    if ('a' == '0' || 'z' == '0') {
      if ('A' == '0' || 'Z' == '0') {
        ++array[c - '0'];
      }
    }

  return 0;
}
