#include <stdio.h>

char* substitute_vowels(char* string, char replace);

int main(){
    char string[100];
    char replace;
    printf("Enter a string \n");
    fgets(string, sizeof(string), stdin);
    printf("%s",string);
    printf("Enter the character to replace the vowels with\n");
    scanf("%c",&replace);
    getchar();
    char * n = substitute_vowels(string, replace);
    printf("%s",n);
    printf("The replaced string is %s\n", string);
    return 0;
}

char* substitute_vowels(char* string, char replace){
    char vowels[5] = {'a','e','i','o','u'};
    for(int i = 0; i < 100; i++){
        char* letter = string + sizeof(char) * i;
        for(int j = 0; j < 5; j++){
            if(*letter == vowels[j]){
                *letter = replace;
                break;
            }
        }       
    }
    return string;  
}