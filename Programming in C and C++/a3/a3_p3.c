/*
CH-230-A
a3_p3.c
Subigya Paudel
spaudel@jacobs-university.de
*/

#include <stdio.h>

float convert(int c);

int main(){
    int x;
    scanf("%d",&x);zl
    printf("Result of conversion: %f\n",convert(x));
    return 0;
}

float convert(int c){
    float k;
    k = (float) c / 100000;
    return k;
}
