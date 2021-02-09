/*
CH-230-A
a2_p5.c
Subigya Paudel
spaudel@jacobs-university.de
*/

#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    printf("Value of a=%d\n", a);
    int *ptr_a = &a;
    printf("Address of a= %p\n", ptr_a);
    printf("New value=%d\n",*ptr_a+5);
    printf("Address of the variable=%p",ptr_a);
    return 0;
}
