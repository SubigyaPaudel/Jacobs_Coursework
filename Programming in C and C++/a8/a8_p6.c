#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr1, *fptr2;
    char a,b;
    int sum;
    fptr1 = fopen("chars.txt","r");
    fptr2 = fopen("codesum.txt", "w");
    if(fptr1 == NULL || fptr2 == NULL){
        printf("Error in opening the file");
        exit(1);
    }
    a = getc(fptr1);
    b = getc(fptr1);
    sum = a + b;
    fprintf(fptr2, "%d", sum);
    fclose(fptr2);
    fclose(fptr1);
    return 0;
}