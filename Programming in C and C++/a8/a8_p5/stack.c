#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* collect(struct stack *collector, char *sentence){
    int pos = 0;
    int words = 0;
    int wordpos = 0;
    char word[30];
    while(sentence[pos] != '\0'){
        if(sentence[pos] != ' ' || sentence[pos] == '\n' || sentence[pos] == ','){
           word[wordpos] = sentence[pos]; 
           wordpos++;
        }else{
            word[wordpos] = '\0';
            for(int i = 0; i <= wordpos; i++)
                collector->container[words][i] = word[i];
            words++;
            wordpos = 0;        
        }
        pos++;
    }
    collector->count = words;
    return collector;
}


