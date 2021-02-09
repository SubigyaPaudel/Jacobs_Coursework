#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    char filename[64], r;
    fgets(filename, 64, stdin);
    filename[strlen(filename)-1] = '\0';
    fptr = fopen(filename, "r");
    r = getc(fptr);
    while(r != EOF){
        printf("%c",r);
        r = getc(fptr);
    }
    printf("Mark");
    fclose(fptr);
    return 0;
}