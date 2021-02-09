/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p9.c
*/

#include <stdio.h>

double sum25(double v[],int n);

int main(){
    int n;
    double i;
    double s;
    scanf("%d",&n);
    double num[n];
    for(int j = 0; j <= n-1 ; j++){
        scanf("%lf", &i);
        num[j]=i;
    }
    s = sum25(num,n);
    if(s!=-111.0){
    printf("sum=%lf\n",s);
    }else{
    printf("One or both positions are invalid\n");
    }
    return 0;
}


double sum25(double v[],int n){
    if (n < 3 || n <= 5) {
        return -111.0;
    }else{
        double s = v[2] + v[5];
        return s;
    }
    }

