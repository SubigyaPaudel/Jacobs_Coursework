/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p10.c
*/

#include <stdio.h>

void recurfunction(int n){
    if(n == 1){
        printf("%d\n",n);
    }else{
        printf("%d",n);
        recurfunction(n);
    }
}

int main(){
    int t;
    printf("Enter a positive integer");
    scanf("%d",&t);
    recurfunction(t);
    return 0;
}
