/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p8.c
*/

#include <stdio.h>

float sum(float arr[], int x){
      float s;
      for(int j = 0; j<= x; j++)
         s += arr[j];
      return s;
}

float avg(float arr[], int x){
    float s, a;
    s = sum(arr , x);
    printf("%f",s);
    a = s / (x+1);
    /* (x+1) is written instead of x, because x is only the index value of the last meaningful float number.
    x+1 is the number of meaningful elements. */
    return a;

}

int main(){
    float num[10];
    int j;
    float s;
    float a;
    for(j = 0 ; j <= 9 ; j++){
        printf("Enter a number \n");
        scanf("%f",&num[j]);
        if(num[j] == -99.0){
            break;
        }

    }
    j--; //this is done to exclude -99.0 from the operations ahead
    s = sum(num, j);
    a = avg(num,j);
    printf("The sum of the numbers is %f \n", s);
    printf("The average of the numbers is %f \n", a);
    return 0;
}
