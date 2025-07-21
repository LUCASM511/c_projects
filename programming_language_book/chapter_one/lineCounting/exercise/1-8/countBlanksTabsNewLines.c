#include <stdio.h>

int main() {

  int c;
  int blanks, tabs, newLines;

  blanks = 0;
  tabs = 0;
  newLines = 0;

  while ((c = getchar() != EOF))
    if (c == '\n')
      ++newLines;
  printf("%d", newLines);
  if (c == '\t')
    ++tabs;
  printf("%d\n", tabs);
  if (c == ' ')
    ++blanks;
  printf("%d\n", blanks);

  return 0;
}
