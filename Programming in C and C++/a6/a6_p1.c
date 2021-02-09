/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p01.c
*/
#include <stdio.h>
#define swap(a,b,type) { type (k) = (b); (b) = (a); (a) = (k); }

int main(){
    int a,b;
    double c,d;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%lf",&c);
    scanf("%lf",&d);
    swap(a,b,int);
    swap(c,d,double);
    printf("After swapping:\n%d\n",a);
    printf("%d\n",b);
    printf("%.6lf\n",c);
    printf("%.6lf\n",d);
    return 0;
}
