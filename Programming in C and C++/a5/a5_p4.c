/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p4.c
*/

#include <stdio.h>
#include <stdlib.h>

void divby5(float *arr, int size){
    for(int j = 0; j <= (size - 1); j++){ // (size -1) because the maximum index value is (size -1)
            arr[j] /= 5;
    }
}

int main(){
    int size;
    float *numbers;
    scanf("%d",&size);
    numbers = (float*) malloc(size * sizeof(float));
    if(numbers == NULL)
        exit(1);
    for(int i = 0; i <= (size - 1); i++){
        scanf("%f",&numbers[i]);
    }
    printf("Before:\n");
    for(int j = 0; j <= (size - 1); j++){
        printf("%f\n",numbers[j]);
    }
    divby5(numbers,size);
    printf("After:\n");
    for(int i = 0; i <= (size - 1); i++){
        printf("%f\n",numbers[i]);
    }
    free(numbers);
    return 0;
}
