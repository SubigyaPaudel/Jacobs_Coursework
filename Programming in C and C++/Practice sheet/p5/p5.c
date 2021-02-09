#include <stdio.h>
#include <stdlib.h>

int odd(unsigned char data);

int main(){
    char c;
    scanf("%c",&c);
    getchar();
    printf("%d",odd(c));
    return 0;
}

int odd(unsigned char data){
    return (data & 1);
}

