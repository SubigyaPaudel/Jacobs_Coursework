/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p1.c
*/

#include <stdio.h>
#include <string.h>

int main(){
    char r[50];
    fgets(r, sizeof(r),stdin);
    for(int i = 0; i <= strlen(r) - 2; i++){
        if(i % 2 == 0){
            printf("%c",r[i]);
        }else{
            printf(" %c",r[i]);
        }
        printf("\n");
        }
    return 0;
}
