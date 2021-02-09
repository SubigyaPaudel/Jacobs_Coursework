#include <stdio.h>
#include "linked_list.h"

int main(){
    struct list *first = NULL;
    int x = 1;
    int n;
    char oper;
    while(x == 1){
        scanf("%c",&oper);
        //getchar();
        switch(oper){
            case 'b':
                scanf("%d",&n);
                getchar();
                first=addfirst(first,n);
                break;
            case 'a':
                scanf("%d",&n);
                getchar();
                first=addlast(first,n);
                break;
            case 'p':
                printlist(first);
                break;
            case 'r':
                first=removefirst(first);
                break;
            case 'q':
                ++x;
                removelist(first);
                break;
        }
    }   
}