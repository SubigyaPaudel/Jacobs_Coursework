/*
CH-230-A
a2_p8.c
Subigya Paudel
spaudel@jacobs-university.de
*/

#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if (n % 2 == 0 && n % 7 == 0){
        printf("The number is divisible by 2 and 7\n");
    }else{
        printf("The number is NOT divisible by 2 and 7\n");
    }
    return 0;
}
