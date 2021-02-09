/*
CH-230-A
a3_p2.c
Subigya Paudel
spaudel@jacobs-university.de
*/


#include <stdio.h>

int main(){
    char c;
    int y;
    scanf("%c", &c);
    getchar();
    scanf("%d",&y);
    getchar();
    for (int j = c ; j >= c-y ; j--){
        printf("%c \n",j);
    }
    return 0;
}
