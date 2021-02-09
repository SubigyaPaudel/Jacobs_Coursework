#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    char thing[100];
    fgets(thing, sizeof(thing), stdin);
    printf("%d \n", (int) strlen(thing));    
    for(int i = 0; i < strlen(thing); i++){
        printf("%c",toupper(thing[i]));
    }
    return 0;
}