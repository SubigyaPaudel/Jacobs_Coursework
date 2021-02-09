/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a4_p11.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_insensitive(char *str, char c){
    int count = 0;
    for(int i = 0; i <= (strlen(str)-1); i++){
        if(tolower(str[i])==c)
            count++;
    }
    return count;
}

int main(){
    char *first;
    char *second;
    int n, count;
    char lookup;
    first = (char*) malloc(50 * sizeof(char));
    if(first == NULL)
        exit(1);
    printf("Enter a string\n");
    fgets(first,50,stdin);
    printf("Enter the character you want to search\n");
    scanf("%c",&lookup);
    getchar();
    n = strlen(first);
    second = (char*) malloc(n);
    if(second == NULL)
        exit(1);
    for(int i = 0; i <= (n-2); i++){
        second[i]=first[i];
    }
    free(first);
    count = count_insensitive(second, lookup);
    printf("%c appears %d times on %s", lookup, count, second);
    free(second);
    return 0;
}
