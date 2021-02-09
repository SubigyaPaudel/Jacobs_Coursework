 # include <stdio .h>
 void output ( void ) {
 printf ("%s\n", " Please enter a number :");
 }
 int sum ( int a, int b) {
 return (a + b);
 }
 int main () {
 int x, y;
 void (* fptr1 )( void );
 int (* fptr2 )(int , int );
 fptr1 = output ;
 fptr2 = sum ;
 fptr1 (); // cannot see whether function or pointer
 scanf ("%d", &x);
 ( fptr1 )(); // some prefer this to show it is pointer
 (* fptr1 )(); // complete syntax , same as above
 scanf ("%d", &y);
 printf ("The sum is %d.\n", fptr2 (x, y));
 }