/*
ch-230a
Subigya Paudel
spaudel@jacobs-university.de
*/

 #include <stdio.h>
 #include <stdlib.h>

int main(){
    int x= 17;
    int y= 4;
    float a = x;
    float b = y;
    int sum = x+y;
    int  pro = x*y;
    int dif = x-y;
	int r = x%y;
	float quo = a/b;
    printf("x=%d \n", x);
    printf("y=%d \n", y);
    printf("sum=%d \n", sum);
    printf("product=%d \n", pro);
    printf("difference=%d \n", dif);
    printf("division=%f \n", quo);
    printf("remainder of the division=%d \n", r);

    return 0;
}
