/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a8_p9.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int belongs(char a){
    char remember[9] = {' ',',','?','!','.','\t','\r','\n'};
    int count = 0;
    for(int i = 0; i < 8; i++){
        if(a == remember[i])
            count++;
    }
    if(count == 0){
        return 0;
    }else{
        return 1;
    }
}

int checksides(char a, char b){
    if(belongs(a) && belongs(b)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    FILE *fptr;
    char current, next;
    char filename[64];
    int words = 0;
    int warn = 0;
    fgets(filename, sizeof(filename), stdin);
    filename[strlen(filename)-1]='\0';
    fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    current = getc(fptr);
    if(current == EOF){
        printf("No. of Words = 0");         // in the case that the file is empty
        return 0;
    }
    while(belongs(current))
        current = getc(fptr);               // taking the file to the first word of the file
    next = getc(fptr);
    while(current != EOF){
        if(belongs(current)){
            if(!checksides(current, next)){
                words++;
            }
        }
        current = next;
        if(!warn)
            next = getc(fptr);
        if(next == EOF)                     // in order to not access beyond the end of file
            warn = 1;
    }
    printf("No. of words = %d",words);
    fclose(fptr);
    return 0;
}