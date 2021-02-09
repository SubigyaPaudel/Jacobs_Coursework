#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct river{
    char name[40];
    int length;
    int drainage_area;
};

int sortbylength(const void* r1, const void* r2){
    struct river* R1 = (struct river*) r1;
    struct river* R2 = (struct river*) r2;
    if(R1->length > R2->length){
        return 1;
    }else if(R1->length < R2->length){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    int (*foo)(const void* a, const void* b);
    FILE* fptr1,*fptr2;
    char name[40];
    int length;
    int drainage_area;
    fptr1 = fopen("file1.txt","r");
    fptr2 = fopen("output2.txt","w");
    if(fptr1 == NULL){
        printf("Error opening file");
        exit(1);
    }
    foo = &sortbylength; 
    struct river Rivers[30];
    int i = 0;

    while(!feof(fptr1)){
        fscanf(fptr1,"%s %d %d", name, &length, &drainage_area);
        strcpy(Rivers[i].name, name);
        Rivers[i].length = length;
        Rivers[i].drainage_area = drainage_area;
        i++;
    }
    qsort(Rivers,i,sizeof(struct river),foo);
    for(int j = 0; j <= i; j++){
        fprintf(fptr2, "%s %d %d\n",Rivers[j].name, Rivers[j].length, Rivers[j].drainage_area);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}