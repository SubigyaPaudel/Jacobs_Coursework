/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p.c
*/

#include <stdio.h>
#include <math.h>

float geometric_mean(float arr[], int n){
    double product = 1;
    double result;
    for(int j = 0 ; j <= n; j++)
        product *= arr[j];
    double expo = 1.0/ ((double) n + 1.0);
    result = (float) pow(product, expo);
    return result;
}

float highest_number(float arr[], int n){
    for(int i = 1; i <= n; i++){
        if(arr[i]<arr[i-1])
            arr[i] = arr[i-1];
    }
    return arr[n];
}

float lowest_number(float arr[], int n){
    for(int i = 1; i <= n; i++){
        if(arr[i]>arr[i-1])
            arr[i] = arr[i-1];
    }
    return arr[n];
}

float sum(float arr[], int n){
    float s;
    for(int i = 0; i <=n ; i++)
        s += arr[i];
    return s;
}

int main(){
    float values[15];
    int k = 0;
    int count = 0;
    char operation;
    float result;
    while (k ==0){
        scanf("%f",&values[count]);
        if(values[count] < 0){
            k++;
            count--;
        }else{
            count++;
        }
    }
    printf("Enter the operation you want to perform\n");
    printf("m: geometric mean \n h: highest number; \n l: lowest number \n s: sum");
    getchar();
    scanf("%c", &operation);
    switch(operation){
        case 'm':
            result = geometric_mean(values, count);
            printf("The geometric mean is %f", result);
            break;
        case 'h':
            result = highest_number(values, count);
            printf("The highest number that had been entered is %f",result);
            break;
        case 'l':
            result = lowest_number(values, count);
            printf("The lowest number that had been entered is %f", result);
            break;
        case 's':
            result = sum(values, count);
            printf("The sum of the numbers entered is %f", result);
            break;
    }
    return 0;
}
