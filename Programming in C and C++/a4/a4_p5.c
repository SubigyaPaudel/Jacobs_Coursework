/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p5.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int *a_ptr;
    int greatest = 0;
    scanf("%d",&a);
    a_ptr = (int*) malloc(sizeof(int) * a);
    if (a_ptr == NULL)
        exit(1);;
    for(int i= 0; i <= (a-1); i++){
        scanf("%d", a_ptr[i]);
        if (i > 0){
            if(a_ptr[i] > a_ptr[i-1])
                greatest = a_ptr[i];
        }
    }
    free(a_ptr);
    printf("%d",greatest);
    return 0;
}
