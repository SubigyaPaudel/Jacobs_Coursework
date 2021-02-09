/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p5.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int logarithm(char n) {
    int e = n;
    double exp = 0;
    while ((double) e > pow(2.0, exp))
        exp++;
    return ((int) exp);
}

int main(){
    char c;
    char work;
    scanf("%c",&c);
    int size = logarithm(c);
    printf("The decimal representation is: %d\n", c);
     printf("The backwards binary representation is: ");
    for(int i = 0; i < size ; i++){
        if(c & 1 << i){
            work = '1';
            printf("%c",work);
        }else{
            work ='0';
            printf("%c",work);
        }
    }
    printf("\n");   
    return 0;
}