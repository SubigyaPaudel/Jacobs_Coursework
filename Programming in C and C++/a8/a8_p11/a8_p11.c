/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a8_p11.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int stringsize(FILE *fptr){
    int give;
    fseek(fptr,0,SEEK_END);
    give = (int) ftell(fptr);
    return give;
}

int main(){
    FILE **list, *result;
    char filename[64];
    char buffer[64];
    int filesize, quotient,remainder, num;
    scanf("%d",&num);
    getchar();
    list = (FILE**) malloc(sizeof(FILE*) * num);
    for(int i = 0; i < num; i++){
        fgets(filename,sizeof(filename), stdin);
        filename[(int) strlen(filename) - 1] = '\0';
        list[i] = fopen(filename,"rb");    
        if(list[i] == NULL){
            printf("Error in opening file");
            exit(1);
        }
    }
    result = fopen("output.txt","wb");
    printf("Concatenating the content of %d files\n", num);
    printf("The result is:\n");
    for(int i = 0; i < num; i++){
        filesize = stringsize(list[i]);
        quotient = filesize / 64;
        remainder = filesize % 64;
        fseek(list[i],0,SEEK_SET);
        fread(buffer, 1, remainder,list[i]);
        fwrite(buffer, 1, remainder, result);
        fseek(list[i], remainder, SEEK_SET);
        fwrite(buffer, remainder, 1, stdout);
        for(int j = 0; j < quotient; j++){
            fseek(list[i], remainder + 64 * j,SEEK_SET);
            fread(buffer, 64, 1, list[i]);
            fwrite(buffer, 64, 1, result);
            fwrite(buffer, 64, 1, stdout);
        }
        }
   
    for(int i = 0; i < num; i++){
        fclose(list[i]);
    }
    free(list);
    fclose(result);
    printf("%s","\nThe result was written is output.txt");
    return 0;
}