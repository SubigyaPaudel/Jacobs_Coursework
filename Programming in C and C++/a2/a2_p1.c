#include <stdio.h>
#include <stdlib.h>

int main()
{
 double x;
    double y;
    int a;
    int b;
    scanf("%lf",&x);
    scanf("%lf",&y);
    printf("sum of doubles = %lf \n",x + y);
    printf("difference of the doubles = %lf \n", x - y);
    printf("square = %lf \n", x*x);
    scanf("%d", &a);
    scanf("%d", &b);
    int sum = a + b;
    int product = a * b;
    printf("The sum of integers %d \n", sum);
    printf("The product of integers %d \n",product);
    char d;
    char c;
    int s1;
    int p1;
    printf("\n Enter two characters");
    getchar();
    scanf("%c", &c);
    getchar();
    scanf("%c", &d);
    s1 = c + d;
    p1 = c * d;
    printf("%c",c);
    printf("sum of chars %d", s1);
    printf("product of chars %d", p1);
    printf("sum of chars %c", s1);
    printf("sum of chars %c", p1);
    return 0;
}
