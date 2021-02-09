/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a7_p2.c
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    char c;
    struct node *prev;
    struct node *next;
};

int count;

struct node* pushfront(struct node *first, char thing){
        if(count == 0){         //to handle the very first input of the runtime
            first->c = thing;
            count++;
            return first;
        }else{
            struct node *helper = (struct node*) malloc(sizeof(struct node));
            if (helper == NULL){
                printf("Error allocating memory\n");
                return first;
            }
            first->prev = helper;
            helper->c = thing;
            helper->next = first;
            helper->prev = NULL;
            return helper;
        }
    }

struct node* eliminate(struct node *first, char thing){
    struct node *i, *assist;
    int k = 0; 
    while(first != NULL){
        if(first->next == NULL)
            assist = first;
        if(first->c == thing){
            if(first->prev == NULL){// the case when the element to be removed is in the beginning of the list
                i = first;
                first = first->next;
                first->prev = NULL;
                k++;
                free(i);
            }else if(first->next == NULL){ // the case when the element is to be removed from the end of the list
                i = first;
                first = first->prev;
                first->next = NULL;
                k++;
                free(i);
            }else{
            (first->prev)->next = first->next;
            (first->next)->prev = first->prev;
            i = first;
            first = first->next;
            k++;
            count++;
            free(i);
            }
        }else{
            first = first->next;
            count++;
        }
    }
    if(k == 0)
        printf("Element not in the list");
    while(assist->prev != NULL)
        assist = assist->prev;
    return assist;
}

void printlist(struct node *first){
    while(first != NULL){  // the last element is empty, so stopping at the second last element
        printf("%c ",first->c);
        first = first->next;
    }
    printf("\n");
}

void printback(struct node* first){
    while(first->next != NULL)
        first = first->next;
    while(first != NULL){
        printf("%c ", first->c);
        first = first->prev;
    }
    printf("\n");
}

void freelist(struct node* first){
    struct node *i;
    while(first != NULL){
        i = first;
        first = first->next;
        free(i);
    }
}

int main(){
    struct node *first = (struct node*) malloc(sizeof(struct node));
    count = 0;
    first->next = NULL;
    first->prev = NULL;
    int operation;
    char thing;
    int k = 0;
    while(k == 0){
        printf("Enter the operation number\n");
        scanf("%d",&operation);
        getchar();
        switch(operation){
            case 1:
                scanf("%c",&thing);
                first = pushfront(first, thing);
                break;
            case 2:
                scanf("%c",&thing);
                first = eliminate(first, thing);
                break;
            case 3:
                printlist(first);
                break;
            case 4:
                printback(first);
                break;
            case 5:
                k++;
                freelist(first);
                break;
        }
    }
    return 0;
}
