#include <stdio.h>
#include <stdlib.h>

struct list{
    int value;
    struct list *next;
};

struct list *first;                     //  a global variable created to access the first element of the list

void deletelist(struct list *p){
    struct list *a;
    while(p != NULL){
        a = p->next;
        free(p);
        p = a;
    }
}

void addfirst(struct list *p, int n){
    struct list *a = (struct list*) malloc(sizeof(struct list));
    if(a == NULL){
        exit(0);
    }
    if(p->next == NULL){
        p->value = n;
    }else{
    a->next = p;
    a->value = n;
    first = a;
    }
}

void addlast(struct list *p, int n){
    struct list *a = (struct list*) malloc(sizeof(struct list));
    if(a == NULL){
        exit(0);
    }
    while (p->next != NULL)
        p = p->next;
    p->next = a;
    a->value = n;
    a->next = NULL;
}

void remfirst(struct list *p){
    first = p->next;
    free(p);
}

void printl(struct list *p){
    struct list *i;
    for(i = p; i; i = p->next){
        printf("%d",i->value);
    }
}

int main(){
    first = (struct list*) malloc(sizeof(struct list));
    if(first == NULL){
        exit(1);
    }
    first->next = NULL;
    int n;
    char oper;
    int x = 0;
    while(x == 0){
    scanf("%c",&oper);
    switch(oper){
        case 'q':
            ++x;
            deletelist(first);
            break;
        case 'p':
            printl(first);
            break;
        case 'a':
            scanf("%d",&n);
            addlast(first,n);
            break;
        case 'b':
            scanf("%d",&n);
            addfirst(first, n);
            break;
        case 'r':
            remfirst(first);
            break;
        }    
    }
    return 0;
}