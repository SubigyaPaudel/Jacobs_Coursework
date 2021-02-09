#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    FILE* fptr;
    printf("Enter the no. of numbers you want to enter\n");
    scanf("%d",&n);
    int* numbers = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter the number\n");
        scanf("%d",&(numbers[i]));
    }
    fptr = fopen("squares.txt","w");
    for(int i = n-1; i >=0 ; i--){
        fprintf(fptr, "%d %d \n", numbers[i], numbers[i] * numbers[i]);
    }
    fclose(fptr);
    free(numbers);
    return 0;
}