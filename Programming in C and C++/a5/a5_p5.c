/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p5.c
*/

#include <stdio.h>
#include <stdlib.h>

float scalarproduct(float *v1, float *v2, int n){
    float prod = 0;
    for(int i = 0; i <= (n-1); i++){
        prod += (v1[i] * v2[i]);
    }
    return prod;
}

void largest(float *v1, int n){
    float largest = v1[0];
    int pos = 0;
    for(int i = 0; i <= (n-1); i++){
        if(v1[i]>largest){
            pos = i;
            largest = v1[i];
        }
    }
    printf("The largest = %f\n",largest);
    printf("Position of largest = %d\n",pos);
}

void smallest(float *v1, int n){
    float smallest = v1[0];
    int pos = 0;
    for(int i = 1; i <= (n - 1); i++){
        if(v1[i] < smallest){
            pos = i;
            smallest = v1[i];
        }
    }
    printf("The smallest = %f\n",smallest);
    printf("Position of smallest = %d\n",pos);
}

int main(){
    int dim;
    float *v1;
    float *v2;
    scanf("%d",&dim);
    v1 = (float*) malloc(dim * sizeof(float));
    v2 = (float*) malloc(dim * sizeof(float));
    if(v1 == NULL || v2 == NULL)
        exit(1);
    for(int j = 1; j <= 2; j++){
        for(int i = 0; i <= (dim-1); i++){
            if(j == 1){
                scanf("%f",&v1[i]);
            }else{
                scanf("%f",&v2[i]);
            }
        }
    }
    printf("Scalar product=%f\n",scalarproduct(v1,v2,dim));
    smallest(v1,dim);
    largest(v1,dim);
    smallest(v2,dim);
    largest(v2,dim);
    free(v1);
    free(v2);
    return 0;
}
