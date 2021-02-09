/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p02.c
*/

#include <stdio.h>
#define check(c) {printf("The least significant digit is %d\n", c&00000001);}

int main(){
    char z;
    scanf("%c",&z);
    printf("The decimal representation is %d\n", z);
    check(z);
    return 0;
}
