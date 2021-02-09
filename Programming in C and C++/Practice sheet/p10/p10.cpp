#include <stdio.h>
#include <stdlib.h>

void printmatrix(int** matrix, int rows, int columnn);

int main(){
    FILE* fptr;
    int rows, columns;
    fptr = fopen("matrix.txt","r");
    if(fptr == NULL){
        printf("Error opening file \n");
        exit(1);
    }
    fscanf(fptr, "%d", &rows);
    fscanf(fptr, "%d", &columns);
    int** matrix = (int**) malloc(sizeof(int*) * rows);
    for(int i = 0; i < rows; i++)
        matrix[i] = (int*) malloc(sizeof(int)*columns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = 0;
        }
    }
    int rpos, cpos, value;
    while(!feof(fptr)){
        fscanf(fptr, "%d",&rpos);
        fscanf(fptr,"%d",&cpos);
        fscanf(fptr, "%d", &value);
        matrix[rpos-1][cpos-1] = value;
    }
    printmatrix(matrix, rows, columns);   
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    printf("%d %d",rows, columns);
    fclose(fptr);
    return 0;
}


void printmatrix(int** matrix,int rows,int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}