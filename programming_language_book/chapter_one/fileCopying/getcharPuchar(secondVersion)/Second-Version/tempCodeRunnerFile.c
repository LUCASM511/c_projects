#include<stdio.h>

int main(){

    /* Verify the value of end of file */
    while (getchar() != EOF)
        printf("EOF = %i", EOF);
        

    return 0;
}