#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE **list, *result;
    char buffer[64];
    char filename[64];
    int num;
    printf("Enter the number of files");
    scanf("%d",&num);
    getchar();
    list = (FILE **) malloc(sizeof(FILE *) * num);
    for(int i = 0; i < num; i++){
        printf("Enter the name of the file");
        fgets(filename,sizeof(filename), stdin);
        filename[strlen(filename) - 1] = '\0';
        list[i] = fopen(filename,"r+b");       
    }
    result = fopen("output.txt","w+b");
    for(int i = 0; i < num; i++){
        fread(buffer,1,64,list[i]);
        fwrite(buffer,1,64,result);
        fprintf(result,"\n");
    }  
    printf("Concatenating the content of %d files\n", num);
    printf("The result is:\n");
    fread(buffer,1,64,result);
    fwrite(buffer,1,64,stdout);
    for(int i = 0; i < num; i++){
        fclose(list[i]);
    }
    printf("The result was written is output.txt");
    fclose(result);
    free(list);
    return 0;
}