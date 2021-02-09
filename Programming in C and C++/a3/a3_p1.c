/*
CH-230-A
a3_p1.c
Subigya Paudel
spaudel@jacobs-university.de
*/


#include <stdio.h>

int main(){
    float x;
    int n = 0;
    scanf("%f",&x);
    getchar();
    while (n < 1){
        scanf("%d",&n);
        getchar();
        if (n<1){
            printf("Input is invalid, reenter value\n");
        }
    }
    for (int i = 1; i <= n; i++){
        printf("%f\n",x);

    }
    return 0;
}
