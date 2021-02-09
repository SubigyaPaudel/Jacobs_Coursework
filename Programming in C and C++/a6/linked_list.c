#include <linked_list.h>

void addfirst(struct list *p, int n){
    struct list *new = (struct list*) malloc(sizeof(struct list));
    if(new == NULL)
        exit(1);
    new->next = p;
    new->value = n;
    first = new;
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

void removefirst(struct list *p){
    int x = 0;
    if(p != NULL){                  // to make sure that we don't attempt to delete from an empty list
    first = p->next;
    free(p);
    }else{
        x++;                          // The function has do do sth to avoid SIG errors
    }
}

void printlist(struct list *p){
    while (p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("%c",'\n');
}
