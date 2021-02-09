#include <stdio.h>
#include <stdlib.h>

struct list{
    char letter;
    struct list* previous;
    struct list* next;
};

struct list* addfirst(struct list* mylist, char element){
    struct list* newelem = (struct list*) malloc(sizeof(struct list));
    if(newelem == NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    newelem->letter = element;
    newelem->previous = NULL;
    newelem->next = mylist;
    return newelem;
}

struct list* deletefromlist(struct list* mylist, char search){
    struct list* cursor = mylist;
    struct list* dummy;
    int i = 0;
    while(cursor != NULL){
        if(cursor->letter == search){
            i++;
            if(cursor->previous == NULL){
                dummy = cursor;
                cursor = cursor->next;
                cursor->previous = NULL;
                mylist = cursor;
                free(dummy);
            }else if(cursor->next == NULL){
                dummy = cursor;
                cursor = cursor->previous;
                cursor->next = NULL;
                free(dummy);
            }else{
                dummy = cursor;
                cursor->next->previous = cursor->previous;
                cursor->previous->next = cursor->next;
                cursor = cursor->next;
                free(dummy);
            }
        }else{
            cursor = cursor->next;
        }
    }
    return mylist;
}

void printlist(struct list* mylist){
    struct list* dummy = mylist;
    do{
        printf("%c \n",dummy->letter);
        dummy = dummy->next;
    }while(dummy != NULL);
}

void printback(struct list* mylist){
    struct list* dummy = mylist;
    while(dummy->next != NULL){
        dummy= dummy->next;
    }
    while(dummy != NULL){
        printf("%c \n",dummy->letter);
        dummy = dummy->previous;
    }
}

void freelist(struct list* mylist){
    struct list* dummy;
    while(mylist->next != NULL){
        dummy = mylist;
        mylist = mylist->next;
        free(dummy);
    }
}

int main(){
    struct list* mylist;
    int action = 0;
    char input;
    while (action != 5){
        printf("Enter a operation number\n");
        scanf("%d",&action);
        getchar();
        switch(action){
            case 1:
                printf("Enter a character\n");
                scanf("%c",&input);
                mylist = addfirst(mylist,input);
                break;
            case 2:
                printf("Enter a character\n");
                scanf("%c",&input);
                mylist = deletefromlist(mylist,input);
                break;
            case 3:
                printlist(mylist);
                break;
            case 4:
                printback(mylist);
                break;
            case 5:
                freelist(mylist);
                break;
            default:
                printf("Invalid command enter the number again\n");
                break;
        }   
    }
    return 0;
}