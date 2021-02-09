/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p6.c
*/

#include <stdio.h>

int main(){
    char c;
    scanf("%c",&c);
    int mask;
    char e;
    printf("The decimal representation is: %d\n",c);
    printf("The binary representation is: ");
    for(int i = 7; i >= 0; i--){
        mask = 1 << i;
        if(c & mask){
            e = '1';
        }else{
            e = '0';
        }
        printf("%c",e);
    }
    printf("\n");
    return 0;
}