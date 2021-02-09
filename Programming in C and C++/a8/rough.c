#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr1;
    long start, end;
    int chars;
    fptr1 = fopen("file1.txt","r");
    start = fseek(fptr1, 0, SEEK_SET);
    end = fseek(fptr1, 0,SEEK_END );
    chars = (end-start) / 2;
    printf("Number of chracters= %d",chars);
    fclose(fptr1);
    return 0;
}