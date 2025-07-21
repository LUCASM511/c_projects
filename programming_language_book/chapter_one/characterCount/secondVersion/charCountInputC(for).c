#include <stdio.h>

/*count characters in input;  2nd version*/

int main() {

  double nc;

  for (nc = 0; getchar() != EOF; nc++)
    ; // for statement require a body on C, but the semicolon isolated
      //(called null statement) is there to satisfy that requeriment

  printf("%.0f\n", nc);

  return 0;
}
