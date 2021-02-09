/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p7.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100];
    char str2[100];
    char *exact;
    int space;
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    space = (strlen(str1) + strlen(str2) - 2);
    exact = (char*) malloc(space * sizeof(char));
    if(exact == NULL)
        exit(1);
    for (int i = 0; i <= (strlen(str1)-2); i++){
        exact[i] = str1[i];
    }
    for (int i = 0; i<= (strlen(str2)-2); i++){
        exact[strlen(str1)-1+i] = str2[i];
    }
    printf("Result of concatenation: ");
    for(int j = 0; j<= space-1; j++){
        printf("%c",exact[j]);
    }
    printf("\n");
    free(exact);
    return 0;
}
