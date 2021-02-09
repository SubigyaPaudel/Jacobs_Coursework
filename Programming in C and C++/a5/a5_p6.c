/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p6.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int number;
    int target;
    float *values;
    float *working;
    printf("Enter the number of floats");
    scanf("%d",&number);
    values = (float*) malloc(number * sizeof(float));
    if(values == NULL)
        exit(1);
    for(int i = 0; i <= (number-1); i++){
        printf("Enter a floating point number");
        scanf("%f",&values[i]);
    }
    for(int j = 0; j <= (number - 1); j++){
        working = values + (sizeof(float) * j);
        if(values[j] < 0.0){
            target = (working - values) / (sizeof(float));
            j = number;
        }
    }
    printf("Before the first negative value:%d elements",target);
    free(values);
    return 0;
}
