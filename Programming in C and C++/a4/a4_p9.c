/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p8.c
*/

#include <stdio.h>
#include <stdlib.h>

int prodminmax(int arr[], int n){
    int helper;
    int k;
    int prod;
    do{
    k=0;
    for(int i = 1; i <= (n-1); i++){
        if(arr[i-1] > arr[i]){
            helper = arr[i-1];
            arr[i-1]=arr[i];
            arr[i]=helper;
            k++;
        }
    }
    }while(k != 0);
    prod = arr[0] * arr[n-1];
    return prod;
    }

int main(){
    int n;
    int *arr;
    int result;
    scanf("%d",&n);
    arr = (int*) malloc(n * sizeof(int));
    for(int i = 0; i <= (n-1); i++)
        scanf("%d",&arr[i]);
    result = prodminmax(arr, n);
    printf("%d",result);
    free(arr);
    return 0;
}
