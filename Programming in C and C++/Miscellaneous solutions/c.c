#include <stdio.h>
int main(){
    float result; /*The result of the division */
int a = 5;
float b = 13.5; /* 2. Hence, b is chosen to be defined to be a floating point number*/
result = a / b; /* 1. Either a or b must be a floating point in order for the result to be a floating point number*/
printf("The result is %f\n", result); /*Since result is a floating point, the formating specification must also be that of a floating point number*/
return 0;
}
