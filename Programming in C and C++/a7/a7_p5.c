/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a7_p5.c
*/

#include <stdio.h>
#include <stdlib.h>

int ascend(const void *i , const void *j){
    const int* a = (const int*) i;        
    const int* b = (const int*) j;
    if(*a > *b)
        return 1;
    else if(*a < *b)
        return -1;
    else
        return 0;
}

int descend(const void *i, const void *j){
    const int* a = (const int*) i;
    const int* b = (const int*) j;
    if(*a < *b)
        return 1;
    else if(*a > *b)
        return -1;
    else
        return 0;
}

int main(){
    int n, *array;
    char action;
    scanf("%d",&n);
    array = (int*) malloc(n * sizeof(int));
    if(array == NULL)
        exit(1);
    for(int i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }
    while(1){
        scanf("%c",&action);
        if(action == 'a'){
            qsort(array, n, sizeof(array[0]), ascend);
            for(int i = 0; i < n ; i++)
                printf("%d ", array[i]);
            printf("\n");
        }
        if(action == 'd'){
            qsort(array, n, sizeof(array[0]), descend);
            for(int i = 0; i < n; i++)
                printf("%d ",array[i]);
            printf("\n");
        }
        if(action == 'e')
            break;
        }
    free(array);
    return 0;
}