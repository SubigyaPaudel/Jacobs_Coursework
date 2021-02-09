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

struct list * addlast(struct list *p, int n){
    struct list *traverse = p;
    struct list *new = (struct list*) malloc(sizeof(struct list));
    if(new == NULL) {
        return p;
    }
    new->value = n;
    new->next = NULL;
    if(p == NULL){
        p = new;
        return p;
    }else{
    while(traverse->next != NULL)
        traverse = traverse->next;
    traverse->next = new;  
    }      
    return p;
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
    struct list *first;
    int x = 0;
    if(p != NULL){                  // to make sure that we don't attempt to delete from an empty list
    first = p->next;
    free(p);
    return first;
    }else{
        x++;                         // The function has do do sth to avoid SIG errors
        return (struct list*) NULL; 
    }
}

void printlist(struct list *p){
    while (p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}
