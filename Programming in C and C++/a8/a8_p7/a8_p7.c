/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a8_p7.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr1, *fptr2, *fptr3;
    double a, b, sum, difference, product, division;
    fptr1 = fopen("file1.txt","r");
    fptr2 = fopen("file2.txt","r");
    fptr3 = fopen("results.txt","w");
    fscanf(fptr1, "%lf", &a);
    fscanf(fptr2, "%lf", &b);
    sum = a + b;
    difference = a - b;
    product = a * b;
    division = a / b;
    fprintf(fptr3, "sum = %lf\n",sum);
    fprintf(fptr3, "difference = %lf\n", difference);
    fprintf(fptr3, "product = %lf\n", product);
    fprintf(fptr3, "quotient = %lf\n", division);
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}