/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p4.c
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char consonants[42] = {'z','x','c','v','b','n','m','s','d','f','g','h','j','k','l','q','w','r','t','y','p'};
int count_consonants(char str[]){
    int k = 0;
    for(int i = 0; i <= 41; i++){
        for(int j = 0; j <= (strlen(str) - 1); j++){
            if (tolower(str[j]) == (consonants[i]))
                k++;
        }
    }
    return k;
}


int main(){
    char str[100];
    int con[100];
    int test = 0;
    int k = 0;
    while(test == 0){
        fgets(str, sizeof(str), stdin);
        con[k]= count_consonants(str);
        if (str[0] == '\n'){
            k--; // -1 to remove the \n from being printed on the next loop.
            ++test;
        }else {
            k++;
        }
    }
    for (int i = 0; i <= k; i++){
        printf("Number of consonants=%d\n",con[i]);
    }
    return 0;
}
