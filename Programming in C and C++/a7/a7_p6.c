/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a7_p6.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person{
    char name[100];
    int age;
};

void sortbyage(struct person* list, int n){
    struct person helper;
    int count, j;
    count = 0;
    do{
        count = 0;
        for(int i = 1; i < n; i++){
            if(list[i].age < list[i-1].age){
                helper = list[i];
                list[i] = list[i-1];
                list[i-1] = helper;
                count++;
            }else if(list[i].age == list[i-1].age){  //to handle the case where both the ages are the same
                j = strcmp(list[i-1].name, list[i].name);
                if(j > 0){
                    helper = list[i-1];
                    list[i-1] = list[i];
                    list[i] = helper;
                    count++;
                }
            }
        }
    }while (count != 0);
    for(int j = 0; j < n ; j++){
        printf("{%s,%d} ",list[j].name,list[j].age);
    }
}

void sortbyname(struct person *list, int n){
    struct person helper;
    int k, count, r;
    do{
        count = 0;
        for(int i = 1; i < n; i++){
            k = strcmp(list[i-1].name, list[i].name);
            if(k > 0){
                helper = list[i-1];
                list[i-1] = list [i];
                list[i] = helper;
                count++;
            }else if(k == 0){       // to handle the cases where both the names are the same;
                r = list[i-1].age - list[i].age;
                if(r > 0){
                    helper = list[i-1];
                    list[i-1] = list[i];
                    list[i] = list[i-1];
                    count++; 
                }
            }
        }
    }while (count != 0);
    for(int j = 0; j < n ; j++){
        printf("{%s,%d} ",list[j].name,list[j].age);
    }
}

int main(){
    struct person *list;
    int n;
    scanf("%d",&n);
    list = (struct person*) malloc(n*sizeof(struct person));
    if(list == NULL)
        exit(1);
    for(int i = 0; i < n; i++){
        getchar();
        fgets(list[i].name,sizeof(list[i].name),stdin);
        list[i].name[strlen(list[i].name)-1] = '\0';
        scanf("%d",&(list[i].age));
    }
    sortbyname(list, n);
    printf("\n");
    sortbyage(list,n);
    free(list);
    return 0;
}