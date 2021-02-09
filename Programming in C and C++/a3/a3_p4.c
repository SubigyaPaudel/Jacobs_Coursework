/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p4.c
*/

#include <stdio.h>

int position(char str[], char c){
int idx;

for (idx = 0; str[idx] != c && str[idx] != '\0' ; ++idx)
    ; /* semicolon added to mark that return idx is not a part of the iteration.
    If return is executed inside the for loop, the whole user-defined
    will terminate after returning the current, inaccurate position of 'g'.*/
return idx;
}

int main() {
char line[80];
while(1){
printf("Enter string:\n");
fgets(line, sizeof(line), stdin);
printf("The first occurrence of 'g' is: %d \n", position(line, 'g') + 1);
return 0;
}
}
