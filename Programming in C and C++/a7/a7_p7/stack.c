#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* push(struct stack *pringles, int chip){
    if(pringles->count >= 12){
        printf("Pushing Stack Overflow\n");
        return pringles;
    }else{
    printf("Pushing %d\n",chip);
    (pringles->count)++;
    int k = pringles->count - 1;
    (pringles->container)[k] = chip;
    return pringles;
    }
}

struct stack* pop(struct stack *pringles){
    int n;
    if(pringles->count == 0){
        printf("Popping Stack Underflow\n");
        return pringles;
    }else{
        n = (pringles->container)[pringles->count-1];
        printf("Popping %d\n", n);
        (pringles->container)[n] = 0;
        (pringles->count)--;
        return pringles;
    }
}

struct stack* empty(struct stack *pringles){
    if(pringles->count == 0){
        printf("Stack Empty\n");
        return pringles;
    }else{
    int n = pringles->count -1 ;
    printf("Emptying Stack ");
    for(int i = n; i>=0; i--){
        printf("%d ",(pringles->container)[i]);
    }
    printf("\n");
    pringles->count = 0;
    return pringles; 
}
}




