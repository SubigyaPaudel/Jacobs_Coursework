/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p3.c
*/

#include <stdio.h>
#include <string.h>

int count_lower(char *str){
    int number = 0;
    for (int j = 0; j <= (strlen(str) - 1); j++){
        if(*(str + (j * sizeof(char))) >= 97 && *(str + (j * sizeof(char))) <= 122){
            number++;
        }
    }
    return number;
}

int main(){
    char str[50];
    int count = 0;
    while (count == 0){
    printf("Enter a string\n");
    fgets(str,sizeof(str),stdin);
    if(*str == '\n')
            break;
    printf("The number of lowercase characters=%d\n",count_lower(str));
    }
    return 0;
}
