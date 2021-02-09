/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p6.c
*/

#include <stdio.h>
#include <stdlib.h>

//Approach: Choosing to iterate through the array a multiple times instead of sorting it.

int main(){
    int number;
    int *arr;
    int first;
    int second;
    int pos;
    printf("Enter the number of integers you want to enter");
    scanf("%d",&number);
    arr = (int*) malloc(number*sizeof(int));
    if (arr == NULL)
        exit(1);
    for(int i = 0; i <= (number-1); i++){
        printf("Enter an integer\n");
        scanf("%d",&arr[i]);
        if(i == 0){
            first = arr[i];
        }
        if(i == 1){
            second = arr[i];
        }else{
            for(int j = 0; j <= i; j++){
                if(arr[j]> first){
                    first = arr[j];
                    pos = j;
                }
            }
            for(int k = 0; k <= i; k++){
                if(k != pos){
                    if(arr[k]> second){
                        second = arr[k];
                    }
                }
            }
        }
    }
    printf("The greatest and second greatest values are %d and %d", first, second);
    free(arr);
    return 0;
}
