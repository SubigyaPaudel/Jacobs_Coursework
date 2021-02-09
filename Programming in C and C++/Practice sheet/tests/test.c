#include <stdio.h>
#include <string.h>

int main(){
    char string1[20];
    char string2[20];
    fgets(string1, sizeof(string1), stdin);
    strcpy(string2,string1);
    printf("%s",string1);
    return 0;
}