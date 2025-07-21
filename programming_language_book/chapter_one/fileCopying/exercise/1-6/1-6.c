#include<stdio.h>

/* Verify that expression 'getchar() != EOF' is 0 or 1*/
int main(){

    /* Output = -1 */
    while (getchar() != EOF)
        printf("%d", EOF);

    return 0;
}