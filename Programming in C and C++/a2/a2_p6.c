/*
CH-230-A
a2_p6.c
Subigya Paudel
spaudel@jacobs-university.de
*/

#include <stdio.h>

int main(){
    double x,y;
    double *ptr_one;
    double *ptr_two;
    double *ptr_three;
    scanf("%lf", &x);
    scanf("%lf", &y);
    ptr_one = &x;
    ptr_two = &x;
    ptr_three = &y;
    printf("ptr_one=%p\nptr_two=%p\n", ptr_one, ptr_two);
    printf("ptr_three=%p",ptr_three);
    return 0;
}
