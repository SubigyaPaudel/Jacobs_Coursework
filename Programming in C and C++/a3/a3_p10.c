/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p9.c
*/

#include <stdio.h>

float product(float a, float b);
void productbyref(float a, float b, float *p);
void modifybyref(float *a, float *b);

int main(){
    float a,b,c,p;
    float *d,*a_ptr, *b_ptr;
    scanf("%f",&a);
    scanf("%f",&b);
    d = &p;
    a_ptr = &a;
    b_ptr = &b;
    c = product(a,b);
    printf("Result of function 'product': %f \n",c);
    productbyref(a,b,d);
    printf("Result of function 'productbyref': %f \n", *d);
    modifybyref(a_ptr, b_ptr);
    printf("Now the values of the entered variables are %f and %f",a,b);
    return 0;
}

float product(float a, float b){
    float r;
    r = a * b;
    return r;
}

void productbyref(float a, float b, float *p){
    *p = a * b;
}

void modifybyref(float *a, float *b){
    *a += 3;
    *b += 11;
    printf("Using the 'modifybyref' function...\n");
    printf("The value of the first variable is %f and the second one is %f \n", *a, *b);
}
