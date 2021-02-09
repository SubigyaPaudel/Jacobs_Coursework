/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p7.c
*/

#include <stdio.h>

void print_form(int n, int m, char c){
    for(int j = n; j <= (n+m-1); j++){
        for(int k = 1; k <= j; k++){
            printf("%c",c); // this loop prints given symbol j times where n<j<
        }
    printf("\n"); // to enter the successive line of the trapezium
    }
}

int main(){
    char c;
    int n, m;
    scanf("%d",&n);
    scanf("%d",&m);
    getchar();
    scanf("%c",&c);
    print_form(m,n,c);
    return 0;
}

