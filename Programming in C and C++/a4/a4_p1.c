/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p1.c
*/

#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846


int main(){
    float initial, last, step;
    scanf("%f",&initial);
    scanf("%f", &last);
    scanf("%f", &step);
    for (float i = initial; i <= last; i += step){
        printf("%f %f %f\n" , i , i * i * pi , 2 * i * pi);
    }
    return 0;
}
