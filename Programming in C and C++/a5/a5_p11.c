/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p11.c
*/

#include <stdio.h>

int isPrime(int n, int a){
    int r, y;
    r = n % a;
    if(n == 1){
        return 0;
    }else if(a == 1){
        return 1;
    }else if(r == 0){
        return 0;
    }else{
        y = isPrime(n,--a);
        return y;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    if(n == 1){
        printf("%d is not prime\n",n);
    }
    else if(isPrime(n,n/2) == 1){
        printf("%d is prime\n",n);
    }else{
        printf("%d is not prime\n",n);
    }
    return 0;
}
