/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p7.c
*/

#include <stdio.h>
#include <stdlib.h>

void printmatrix(int matrix[30][30],int n){
    printf("The entered matrix is:\n");
    for(int i=0; i <= (n-1); i++){              // a block to get the elements of a matrix printed
        for(int j = 0; j <= (n-1); j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

void underthemaindiagonal(int matrix[30][30], int n){
    printf("Under the main diagonal:\n");
    for(int i = 0; i <= (n-1); i++){
        for(int j = 0; j <=(n-1); j++){
            if(i > j)
                printf("%d ", matrix[i][j]);
        }
    }
}

int main(){
    int matrix[30][30];
    int n;
    scanf("%d",&n);
    for(int i = 0; i <= (n-1); i++){
        for(int j = 0; j <= (n-1); j++)
            scanf("%d",&matrix[i][j]);
    }
    printmatrix(matrix, n);
    underthemaindiagonal(matrix ,n);
    printf("\n");
    return 0;
}


