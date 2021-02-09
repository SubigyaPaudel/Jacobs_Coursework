/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p5.c
*/

#include <stdio.h>

void print(double arr[], int n){
    printf("The values of the temperatures are: \n");
    for (int j = 0; j <= (n-1) ; j++){
        printf("%lf \n", arr[j]);
    }
}

double sum(double arr[], int n){
    double s;
    for (int j = 0; j <= (n-1) ; j++)
        s += arr[j];
    return s;
    }

void convert(double arr[], int n){
    double x;
    printf("The list of temperatures in Fahrenheit is as follows: \n");
    for(int j = 0; j<= (n-1); j++){
        x = (9.0/5.0) * arr[j] + 32;
        printf("%lf \n", x);
    }
}

double average(double arr[], int n){
    double a;
    a = sum(arr,n)/n;
    return a;

}

int main(){
    double t[100];
    int n;
    char c;
    printf("Enter the operation that you want to perform: \n s for sum \n p for list of temperatures \n t for the conversion to Fahrenheit \n");
    scanf("%c",&c);
    getchar();
    printf("Enter the number of entries you want to make \n");
    scanf("%d",&n);
    for(int j=0; j <= n-1 ; j++){
        printf("Enter the temperature \n");
        scanf("%lf", &t[j]);
    }
    switch(c){
        case 'p':
            print(t,n);
            break;
        case 's':
            printf("The sum of the temperatures is: %lf" , sum(t,n));
            break;
        case 't':
            convert(t,n);
            break;
        default:
            printf("The average of the temperatures is: %lf", average(t,n));
    }
    return 0;
}
