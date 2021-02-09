/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p9.c
*/

#include <stdio.h>
#include <stdlib.h>

void readvalues(int ***arr, int r,int c,int d){
    for(int i = 0; i <= (r-1); i++){
        for(int j = 0; j <= (c-1); j++){
            for(int k = 0; k <= (d-1); k++){
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
}

void printspace(int ***arr, int r, int c, int d){
    for(int i = 0; i <= (d-1); i++){
        printf("Section %d:\n", (i+1));
        for(int j = 0; j <= (r-1); j++){
            for(int k = 0; k <= (c-1); k++){
                printf("%d ",arr[j][k][i]);
                  printf("%d %d %d\n",i,j,k);
            }
            printf("\n");
        }
        }

    }


int main(){
    int ***space;
    int r,c,d;
    scanf("%d",&r);
    scanf("%d",&c);
    scanf("%d",&d);
    space = (int***) malloc(d * sizeof(int**));
    for(int i = 0; i <= (d-1); i++){
        space[i] = (int**) malloc(r * sizeof(int*));
        for(int j = 0; j <= (r-1); j++){
            space[i][j] = (int*) malloc(c * sizeof(int));
        }
    }
    readvalues(space,r,c,d);
    printspace(space,r,c,d);
    for(int i = 0; i <= (d-1); i++){
        for(int j = 0; j <= (r-1); j++)
            free(space[i][j]);
        free(space[i]);
    }
    free(space);
    return 0;
}
