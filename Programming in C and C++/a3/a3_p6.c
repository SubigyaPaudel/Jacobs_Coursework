/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p6.c
*/

#include <stdio.h>

float to_pounds(int kg, int g){
    float s, p;
    s = (float) kg + ((float) g)/1000.0;
    p = 2.2 * s;
    return p;
}

int main(){
    int kg, g;
    float p;
    scanf("%d",&kg);
    scanf("%d",&g);
    p = to_pounds(kg, g);
    printf("Result of conversion: %f\n",p);
    return 0;
}

