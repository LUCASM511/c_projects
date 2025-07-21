#include <stdio.h>

/*	read a character
        while (character is not end-of-file indicator)
                output the character just read
                read a character
*/

/* COPY INPUT TO OUTPUT: 1s VERSION */

int main() {

  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }

  return 0;
}
