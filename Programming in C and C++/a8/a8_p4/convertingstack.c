#include <stdio.h>
#include "stack.h"

int main(){
    struct stack b;
    b.count = 0;
    int n, r, u;
    scanf("%d",&n);
    u = n; 
    while(n != 0){
        r = n % 2;
        n /= 2;
        b = *push(&b, r);
    }
    printf("The binary representation of the %d: ", u);
    b = *empty(&b);
    return 0;    
}