#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char str[20];
    struct node* next;
};

struct node* insertbegin(struct node* n, char str[]);
void printnode(struct node* n);

int main(){
    char entry[20];
    struct node* a = NULL;
    printf("before");
    strcpy(entry,"Continue");
    printf("after");
    printf("\n%s\n", entry);
    printf("%d\n", strcmp(entry, "Abort\n"));
    while(strcmp(entry, "Abort\n")!=0){
        printf("Enter a string\n");
        fgets(entry,sizeof(entry),stdin);
        a = insertbegin(a,entry);
    }
    printnode(a);
    return 0;
}

struct node* insertbegin(struct node* n, char str[]){
    struct node* newbeginning;
    newbeginning =(struct node *)malloc(sizeof(struct node));
    if(n == NULL){
        newbeginning->next = NULL;
        
    }else{
        newbeginning->next = n;
    }
    strcpy(newbeginning->str,str);
    return newbeginning;
}

void printnode(struct node* n){
    while(n != NULL){
        printf("%s ", n->str);
        n = n->next;
    }
}