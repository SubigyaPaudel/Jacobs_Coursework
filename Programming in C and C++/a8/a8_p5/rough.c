#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char **sentence;
    sentence = (char**) malloc(sizeof(char*) * 5);
    if(sentence == NULL)
        exit(1);
    for(int i = 1; i <= 5; i++){
        sentence[i] = (char*) malloc(sizeof(char) * 30);
        if(sentence[i] == NULL)
            exit(1);
    }
    for(int i = 0; i < 5; i++){
        fgets(sentence[i],sizeof(sentence[i]), stdin);
    }
    printf("%c",sentence[0][2]);
    for(int i = 0; i < 5 ; i++)
        printf("%s",sentence[i]);
    for(int i = 0; i < 5; i++)
       free(sentence[i]);
    free(sentence);
    return 0;
}