/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p3.c
*/

#include <stdio.h>
#define calculate(max,min,result) {result = ((float) max + (float) min)/2.0;}
#define initialize(min, max, arr) {min = arr[0]; max = arr[0];}
#define findmin(arr,min) {if(arr[i] < min) min = arr[i]; }
#define findmax(arr,max) {if (arr[i] > max) max = arr[i]; }

int main(){
    int list[3], min, max;
    float result;
    scanf("%d",list);
    scanf("%d",&list[1]);
    scanf("%d",&list[2]);
    initialize (min,max,list); // a macro containing statements to suppose the minimum and maximum values in an array
    for(int i = 1; i  <  3;  i++){
            findmin(list,min);   // a conditional statement to find the minimum value in the array
            findmax(list,max);  // a conditional statement to find the maximum value in the array
    }
    calculate(min,max,result); //a macro containing statements for the calculation of mid-range
    printf("The mid-range is: %lf\n",result);
    return 0;
}
