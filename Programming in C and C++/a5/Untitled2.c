for(int i = 0; i < dim; i++){
    for(int j = 0; j < dim; j++){
        for(int k = 0; k < dim; k++){
            p[i][j] += m[i][k]* n[k][j];
        }
    }
}
