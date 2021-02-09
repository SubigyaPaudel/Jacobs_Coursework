#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct list* addfirst(struct list *p, int n){
    struct list *new = (struct list*) malloc(sizeof(struct list));
    if(new == NULL)
        exit(1);
    new->next = p;
    new->value = n;
    return new;
}

void addlast(struct list *p, int n){
    struct list *traverse = p;
    struct list *new = (struct list*) malloc(sizeof(struct list));
    if(new == NULL)
        exit(1);
    new->value = n;
    new->next = NULL;
    if(p == NULL){
        first = new;
    }else{
    while(traverse->next != NULL)
        traverse = traverse->next;
    traverse->next = new;  
    }      
}

void removelist(struct list *p){
    struct list *a;
    while(p != NULL){
        a = p->next;
        free(p);
        p = a; 
    }
}

struct list* removefirst(struct list *p){
    int x = 0;
    if(p != NULL){                  // to make sure that we don't attempt to delete from an empty list
    struct list *new = p->next;
    free(p);
    }else{
        x++;                          // The function has do do sth to avoid SIG errors
    }
    return new;    
}

void printlist(struct list *p){
    while (p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("%c",'\n');
}
