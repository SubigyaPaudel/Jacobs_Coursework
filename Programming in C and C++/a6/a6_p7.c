/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p7.c
*/

#include <stdio.h>

void set3bits(char c, int f, int s, int t){
    printf("After setting the bits: ");
    for(int i = 7; i >= 0; i--){
        if(i == f || i == s || i ==t ){
            printf("%c",'1');
        }else if(c&1<<i){
            printf("%c",'1');
        }else{
            printf("%c",'0');
        }
    }
    printf("%c",'\n');
}

void tobinary(char c){
    printf("The binary representation is: ");
    for(int i = 7; i >= 0; i--){
        if(c&1<<i){
            printf("%c", '1');
        }else{
            printf("%c",'0');
        }
    }
    printf("%c",'\n');
}


int main(){
    char c;
    int f,s,t;
    scanf("%c",&c);
    getchar();
    scanf("%d",&f);
    scanf("%d",&s);
    scanf("%d",&t);
    printf("The decimal representation is: %d\n",c);
    tobinary(c);
    set3bits(c,f,s,t);
    return 0;
}
