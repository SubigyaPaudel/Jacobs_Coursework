#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replaceall(char *str, char c, char e){
    int n = strlen(str);
    for(int i = 0; i <= n-1; i++){
        if(str[i]==c){
            str[i]=e;
        }
    }
}

int main(){
    char str[80];
    char c;
    char e;
    int k = 0;
    while (k != 1){
    printf("Enter a string\n");
    fgets(str, sizeof(str),stdin);
    k = strcmp(str,"stop");
    printf("Enter the character to be replaced\n");
    scanf("%c",&c);
    getchar();
    printf("Enter the character that replaces the aforementioned character\n");
    scanf("%c",&e);
    getchar();
    replaceall(str, c, e);
    printf("The new string is %s\n",str);
    }
    return 0;
}
