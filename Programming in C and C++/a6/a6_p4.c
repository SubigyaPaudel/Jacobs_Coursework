/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p4.c
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef INTERMEDIATE
    #undef perform
#endif
#ifndef INTERMEDIATE
    #undef intermediate
#endif

void perform(int *v1, int *v2, int n){
    int sum =0;
    for(int i = 0; i < n; i++){
        sum += v1[i]*v2[i];
    }
    printf("The scalar product is %d\n", sum);
}

void intermediate(int *v1, int *v2, int n){
    int process;
    int sum;
    printf("The intermediate values are:\n");
    for(int i = 0; i < n; i++){
        process = v1[i] * v2[i];
        sum +=process;
        printf("%d\n", process);
    }
    printf("The scalar product is: %d\n", sum);
}


int main(){
    int n, *v1, *v2;
    scanf("%d",&n);
    v1 = (int*) malloc(n * sizeof(int));
    v2 = (int*) malloc (n *sizeof(int));
    printf("Enter vector 1\n");
    for(int j = 0; j < n; j++){
        printf("Enter component %d\n", (j+1));
        scanf("%d",&v1[j]);
    }
    printf("Enter vector 2\n");
    for(int j = 0; j < n; j++){
        printf("Enter component %d\n", (j+1));
        scanf("%d",&v2[j]);
    }
    perform(v1,v2,n);
    intermediate(v1,v2,n);
    free(v1);
    free(v2);
    return 0;
}

