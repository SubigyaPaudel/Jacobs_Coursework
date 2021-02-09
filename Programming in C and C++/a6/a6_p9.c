/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a6_p9.c
*/

#include <stdio.h>
#include <stdlib.h>

struct list{
    int value;
    struct list *next;
};

struct list *first;              // a global variable for storing the element of the list       

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

int countlist(struct list *p){
    int count = 0;
    while(p != NULL){
        p = p->next;
        count++;
    }
    return count;
}

void reverselist(struct list *p){
    int *helper = (int*) malloc (sizeof(int) * countlist(p));
    if(helper == NULL){
        exit(1);
    }
    int index = 0;
    int maxindex = countlist(p) - 1 ;
    struct list *a = p;
    while(a != NULL){                  // copying elements of the list into an array
        helper[index] = a->value;
        a = a->next;
        index++;
    }
    index = 0;
    while(p != NULL){
        p->value = helper[maxindex-index];
        ++index;
        p = p->next;
    }
    free(helper);
}

void insert(struct list *p, int pos, int n){
    if(pos > (countlist(p)-1) || pos < 0){
        printf("Invalid position\n!");
    }else if(pos == 0){
        struct list *new = (struct list*) malloc(sizeof(struct list));
        new->next = p;
        new->value = n;
        first = new;
    }else{
        struct list *new = (struct list*) malloc(sizeof(struct list));
        new->value = n;
        for(int i = 1; i <= (pos-1); i++)            // iterating in order to reach the (pos-1) element of the list
            p = p->next;
        new->next = p->next;                         //p is pointing to the pos-1 element of the list
        p->next = new;
    }
}

int main(){
    first = NULL;
    int x = 1;
    char oper;
    int pos;
    int n;
    while(x == 1){
        scanf("%c",&oper);
        getchar();
        switch(oper){
            case 'b':
                scanf("%d",&n);
                getchar();
                addfirst(first,n);
                break;
            case 'a':
                scanf("%d",&n);
                getchar();
                addlast(first,n);
                break;
            case 'p':
                printlist(first);
                break;
            case 'r':
                removefirst(first);
                break;
            case 'q':
                ++x;
                removelist(first);
                break;
            case 'R':
                reverselist(first);
                break;
            case 'i':
                scanf("%d",&pos);
                getchar();
                scanf("%d",&n);
                getchar();
                insert(first, pos, n);
                break;
        }
    }   
    return 0;
}

