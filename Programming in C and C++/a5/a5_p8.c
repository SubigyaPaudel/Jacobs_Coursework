/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p8.c
*/

#include <stdio.h>
#include <stdlib.h>

void entermatrix(int **arr, int dim){
    for(int j = 0; j<= (dim-1); j++){
        for(int k = 0; k <= (dim-1); k++){
            scanf("%d",&arr[j][k]);
        }
    }
}

void printmatrix(int **arr, int dim){
    for(int j = 0; j<= (dim-1); j++){
        for(int k = 0; k <= (dim-1); k++)
            printf("%d",arr[j][k]);
        printf("\n");
    }
}

void createspace(int **arr, int dim){
    arr = (int**) malloc(dim * sizeof(int*));
    if(arr == NULL)
        exit(1);
    for(int i = 0; i <= (dim-1); i++){
        arr[i]= (int*) malloc(dim * sizeof(int));
        if(arr[i]==NULL)
            exit(1);
    }
}

void clearspace(int **arr, int dim){
    for(int i = 0; i <= (dim - 1); i++){
        free(arr[i]);
    }
    free(arr);
}

void initialize(int **arr, int dim){
    for(int i = 0; i <= (dim-1); i++){
        for(int j = 0; j <= (dim-1); j++){
            arr[i][j] = 0;
        }
    }
}

int main(){
    int **m = 0;
    int **n = 0;
    int **p = 0;
    int ndim;
    int mdim;
    int pdim;
    scanf("%d",&mdim);
    scanf("%d",&ndim);
    scanf("%d",&pdim);
    createspace(m,mdim);
    createspace(n,ndim);
    createspace(p,pdim);
    printf("Enter matrix m\n");
    entermatrix(m,mdim);
    printf("Enter matrix n\n");
    entermatrix(n,ndim);
    initialize(p,pdim);
    for(int i = 0; i < pdim; i++)
        for(int j = 0; j < pdim; j++)
            for(int k = 0; k < pdim; k++)
                p[i][j] += m[i][k] * n[k][j];
    printf("Matrix m\n");
    printmatrix(m,mdim);
    printf("Matrix n\n");
    printmatrix(n,ndim);
    printf("m X n =\n");
    printmatrix(p,pdim);
    clearspace(m,mdim);
    clearspace(n,ndim);
    clearspace(p,pdim);
    return 0;
}

