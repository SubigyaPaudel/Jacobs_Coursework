/*
ch_230a
Subigya Paudel
spaudel@jacobs-university.de
a5_p8.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int **m,**n,**p;
    int mdim, ndim, pdim;
    scanf("%d",&mdim);
    scanf("%d",&ndim);
    scanf("%d",&pdim);
    m = (int**) malloc(mdim*sizeof(int));
    if(m == NULL)
        exit(1);
    for(int i = 0; i <=(mdim-1); i++){
        m[i] = (int*) malloc(mdim*sizeof(int));
        if(m[i]==NULL)
            exit(1);
    }
    n = (int**) malloc(ndim*sizeof(int));
    if(n == NULL)
        exit(1);
    for(int i = 0; i <=(ndim-1); i++){
        n[i] = (int*) malloc(ndim*sizeof(int));
        if(n[i]==NULL)
            exit(1);
    }
    p = (int**) malloc(pdim*sizeof(int));
    if(p == NULL)
        exit(1);
    for(int i = 0; i <= (pdim-1) ; i++){
        p[i] = (int*) malloc(pdim*sizeof(int));
        if(p[i]==NULL)
            exit(1);
    }
    printf("Enter matrix m\n");
    for(int j = 0; j<= (mdim-1); j++){
       for(int k = 0; k <= (mdim-1); k++){
            scanf("%d",&m[j][k]);
        }
    }
    printf("Enter matrix n\n");
    for(int j = 0; j<= (ndim-1); j++){
       for(int k = 0; k <= (ndim-1); k++){
            scanf("%d",&n[j][k]);
        }
    }
    for(int j = 0; j<= (pdim-1); j++){
       for(int k = 0; k <= (pdim-1); k++){
            p[j][k] = 0;
        }
    }
    for(int i = 0; i < pdim; i++)
        for(int j = 0; j < pdim; j++)
            for(int k = 0; k < pdim; k++)
                p[i][j] += m[i][k] * n[k][j];
    printf("Matrix m\n");
    for(int i = 0; i <= (mdim-1); i++){
        for(int k = 0; k <= (mdim-1); k++){
            printf("%d ",m[i][k]);
        }
        printf("\n");
    }
    printf("Matrix n\n");
    for(int i = 0; i <= (ndim-1); i++){
        for(int k = 0; k <= (ndim-1); k++){
            printf("%d ",n[i][k]);
        }
        printf("\n");
    }
    printf("m X n =\n");
    for(int i = 0; i <= (pdim-1); i++){
        for(int k = 0; k <= (pdim-1); k++){
            printf("%d ",p[i][k]);
        }
        printf("\n");
    }
    for(int i = 0; i <= (mdim-1); i++){
        free(m[i]);
    }
    free(m);
    for(int i = 0; i <= (ndim-1); i++){
        free(n[i]);
    }
    free(n);
    for(int i = 0; i <= (pdim-1); i++){
        free(p[i]);
    }
    free(p);
    return 0;
}
