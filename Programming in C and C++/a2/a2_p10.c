/*
CH-230-A
a2_p10.c
Subigya Paudel
spaudel@jacobs-university.de
*/

#include <stdio.h>

int main(){
    int d;
    int k = 1;
    printf("Enter the number of days\n");
    scanf("%d", &d);
    getchar();
    while ( d < 1 || (d % 1) != 0){
        printf("Enter the number of days again\n");
        scanf("%d", &d);
        getchar();
    }
    while(k <= d){
        if(k == 1){
        printf("%d day = %d hours \n", k , 24 * k);
        }else{
        printf("%d days = %d hours \n" , k , 24 * k);
        }
        k++;
    }
    return 0;
}
