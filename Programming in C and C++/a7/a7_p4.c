/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a7_p4.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int toggle(int thing){
    char i;
    if(thing >= 65 && thing <= 90){
        i = tolower(thing);
        return i; 
    }else if(thing >= 97 && thing <= 122){
        i = toupper(thing);
        return i; 
    }else{
        return thing;
    }
}

void modifier(char* thing, int k){
    int (*fct)(int);
    switch(k){
        case 1:
        fct = &toupper;
        break;
        case 2:
        fct = &tolower;
        break;
        case 3:
        fct = &toggle;
        break;
    }
    for(int i = 0; i < strlen(thing); i++){
        printf("%c",fct(thing[i]));
    }
}

int main(){
    int operation;
    char thing[100];
    fgets(thing, sizeof(thing), stdin);
    do{
        scanf("%d",&operation);
        if(operation == 4)
            break;
        modifier(thing, operation);
    }while(1);
    return 0;
}