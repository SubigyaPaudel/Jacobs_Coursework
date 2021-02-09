#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[64];
    fgets(name, sizeof(name), stdin);
    printf("%d", (int) strlen(name));
    return 0;
}   