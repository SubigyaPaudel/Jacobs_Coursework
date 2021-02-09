#include <stdio.h>
#include "stack.h"

int main(){
    struct stack pringle;
    pringle.count = 0;
    struct stack* pringles = &pringle;
    int input;
    int k = 0;
    char comm;
    while(k == 0){
        scanf("%c",&comm);
        switch(comm){
            case 's':
                scanf("%d",&input);
                pringles = push(pringles,input);
                break;
            case 'p':
                pringles = pop(pringles);
                break;
            case 'e':
                pringles = empty(pringles);
                break;
            case 'q':
                printf("Quit");
                k++;
                break;
        }
    }
    printf("\n");
    return 0;    
}