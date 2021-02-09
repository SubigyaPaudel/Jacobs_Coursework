#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int value;
    struct list* next;
} list;

list* addbegin(list* mylist, int value);
list* addend(list* mylist, int value);
list* removefirst(list* mylist);
void printlist(list* mylist);
void deletelist(list* mylist);
list* addtoposition(list* mylist, int position, int element);
int elemcount(list* mylist);

int main(){
    list* mylist = NULL;
    char action = 't';
    int num;
    while(action != 'q'){
        printf("Enter the operation character\n");
        scanf("%c",&action);
        switch(action){
            case 'a':
                printf("Enter a number:\n");
                scanf("%d",&num);
                mylist = addend(mylist,num);
                break;
            case 'b':
                printf("Enter a number\n");
                scanf("%d",&num);
                mylist = addbegin(mylist,num);
                break;
            case 'i':
                printf("Enter the element\n");
                int position;
                scanf("%d",&num);
                printf("Enter the position of the list\n");
                scanf("%d",&position);
                mylist = addtoposition(mylist,position,num);
                break;
            case 'p':
                printlist(mylist);
                break;
            case 'r':
                mylist = removefirst(mylist);
                break;
            case 'c':
                printf("Count: %d \n",elemcount(mylist));
                break;
            default:
                printf("Invalid command enter a command again\n");
        }
    }
    deletelist(mylist);
    return 0;
}

list* addbegin(list* mylist, int value){
    list* new = (list*) malloc(sizeof(list));
    if(new == NULL){
        printf("Error allocating memory");
        exit(1);
    }
    new->value = value;
    new->next = mylist;
    return new;
}

list* addend(list* mylist, int value){
    list* new = (list*) malloc(sizeof(list));
    if(new == NULL){
        printf("Error allocating memory");
        exit(1);
    }
    new->value = value;
    new->next = NULL;
    if(mylist == NULL)
        return new;
    list* cursor = mylist;
    while(cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = new;
    return mylist;
}

void printlist(list* mylist){
    while(mylist != NULL){
        printf("%d \n", mylist->value);
        mylist = mylist->next;
    }
}

void deletelist(list* mylist){
    list* pawn;
    while(mylist != NULL){
        pawn = mylist;
        mylist = mylist->next;
        free(pawn);
    }
}

list* removefirst(list* mylist){
    list* pawn;
    pawn = mylist;
    mylist = mylist->next;
    free(pawn);
    return mylist;
}

list* addtoposition(list* mylist, int position, int element){
    list* newelem = (list*) malloc(sizeof(list));
    list* cursor = mylist;
    int current = 0;
    while(current < position-1){
        cursor = cursor->next;
        current++;
    }
    newelem->value = element;
    newelem->next = cursor->next;
    cursor->next = newelem; 
    return mylist;
}

int elemcount(list* mylist){
    int number = 0;
    list* dummy = mylist;
    while(dummy != NULL){
        number++;
        dummy = dummy->next;
    }
    return number;
}

/*
Questions:
1. Why is the invalid operator message being printed regardless of the fact that the condition is such that the
else statement is never reached

2. How do I insert an element to a given position in a linked list

*/