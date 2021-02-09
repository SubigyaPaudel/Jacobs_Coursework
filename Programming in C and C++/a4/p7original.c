#include <stdio.h>
#include <stdlib.h>

int main(){
    int **matrix;
    int *store1;
    int *store2;
    int n;
    scanf("%d",&n);
    matrix = (int**) malloc(n * sizeof(int*));
    if(matrix == NULL)
        exit(1);
    for(int i = 0; i <= (n-1) ; i++){
        matrix[i]= (int*) malloc(sizeof(int) * n);
        if(matrix[i]==NULL)
            exit(1);
    }
    for(int k = 0; k <= (n-1); k++){
        store1 = matrix[k];
        for(int y = 0; y <= (n-1); y++){
            store2 = store1 + (y * sizeof(int));
            scanf("%d",store2);
        }
    }
    printf("The entered matrix is:\n");
    for(int p = 0; p <= (n-1); p++){
        store1 = matrix[p];
        for(int q = 0; q <= (n-1); q++){
            store2 = store1 + (q * sizeof(int));
            printf("%d ", *store2);
        }
        printf("\n");
    }
    printf("Under the main diagonal:\n");
    for(int r = 0; r <= (n-1); r++){
        store1 = matrix[r];
        for(int c = 0; c <= (n-1); c++){
            store2 = store1 + (c * sizeof(int));
            if(c < r)
                printf("%d ",*store2);
        }
    }
    printf("\n");
    for(int j = 0; j <= (n-1); j++){
        free(matrix[j]);
    }
    free(matrix);
    return 0;
}
