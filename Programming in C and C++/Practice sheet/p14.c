#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fptr;
    fptr = fopen("generate.txt","w");
    if(fptr == NULL){
        printf("Error opening file \n");
        exit(1);
    }
    char buffer[6];
    for(int i = 0; i< 10; i++){
        for(int j = 0; j < 5; j++){
            buffer[j] = 97 + i;
        }
        buffer[2] = ' ';
        buffer[4] = '\n';
        buffer[5] = '\0';
        fwrite(buffer, 5,1,fptr);
    }
    fclose(fptr);
    return 0;
}