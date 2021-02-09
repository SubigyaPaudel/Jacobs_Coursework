/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a3_p11.c
*/

#include <stdio.h>
#include <string.h>

void conc(char arr1[], char arr2[]){
    printf("concatenation=");
    for(int j = 0; j <= (strlen(arr1) - 2); j++)
        printf("%c",arr1[j]);

    for(int j = 0; j <= (strlen(arr2) -2); j++)
        printf("%c",arr2[j]);

    printf("\n");

}

int main(){
    char one[100];
    char two[100];
    char three[100];
    char search;
    int i;
    int t;
    int k = 0;
    // declared all the variables
    fgets(one, sizeof(one),stdin);
    fgets(two, sizeof(two), stdin);
    scanf("%c",&search);
    getchar();
    // got all the required strings and characters
    int l1 = strlen(one)-1; // 1 is subtracted in order remove \0 from the count
    int l2 = strlen(two)-1; // same as the above comment
    printf("length1=%d\n", l1);
    printf("length2=%d\n", l2);
    // printed the lengths of the strings
    conc(one,two);
    // concatenated the strings
    strcpy(three, two);
    printf("copy=%s",three);
    // copied the string into a third string
    i = strcmp(one,two);
    if(i == 0){
        printf("one is equal to two\n");
    }else if(i >= 0){
        printf("one is larger than two\n");
    }else{
        printf("one is smaller than two\n");
    }
    // compared the two strings
    for(int j = 0; j <= strlen(two); j++){ // loop to search the position of the character.
        if(two[j]==search && k == 0){
            t = j;
            k++;
        }
    }
    if(k == 0){
        printf("The character is not in the string\n");
    }else{
        printf("position=%d\n",t);
    }
    return 0;
}
