#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void divby5(float arr[], int size){
    float *r;
    for(int i = 0; i <= (size - 1); i++){
        r = &arr[i];
        *r = arr[i]/5.0;
    }
}

int main(){
    float arr[] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    printf("Before:\n");
    for(int i = 0; i <= 5; i++)
        printf("%.3f ",arr[i]);
    printf("\nAfter:\n");
    divby5(arr, 6);
    for(int i = 0; i <= 5; i++)
        printf("%.3f ",arr[i]);
    printf("\n");
    return 0;
}
