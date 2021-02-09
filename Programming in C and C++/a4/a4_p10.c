/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p10.c
*/

#include <stdio.h>
#include <math.h>

void proddivpowinv(float a, float b, float *prod, float *div, float *pow, float *invb){
    float p = 1;
    *prod = a * b;
    *div = a / b;
    for(int i = 1; i<=b; i++){
        p *= a;
    }
    *pow = p;
    *invb = 1.0/b;
}

int main(){
    float a;
    float b;
    float prod1;
    float div1;
    float pow1;
    float invb1;
    printf("Enter a number\n");
    scanf("%f",&a);
    printf("Enter a number\n");
    scanf("%f",&b);
    proddivpowinv(a,b,&prod1,&div1,&pow1,&invb1);
    printf("a multiplied by b=%f\n",prod1); // the memory addresses prod, div, pow and invb contain the addresses of the results. So printing them..
    printf("a divided by b=%f\n", div1);
    printf("a raised to to the power b=%f\n", pow1);
    printf("b's inverse=%f\n", invb1);
    return 0;
}
