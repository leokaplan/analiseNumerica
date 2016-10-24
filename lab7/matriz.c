#include "matriz.h"
#include <stdlib.h>

double** mat_cria (int m, int n){
    int i;
    double** mat = malloc(m*sizeof(double));
    for(i = 0;i<m;i++){
        mat[i] = (double*)malloc(n*sizeof(double)); 
    }
    return mat;
}
void mat_libera (int m, double** A){
    int i;
    for(i = 0;i<m;i++){
        free(A[i]); 
    }
    free(A);
}
void mat_transposta (int m, int n, double** A, double** T){
    int i,j;
    for(i = 0;i<m;i++){
        for(j = 0;j<n;j++){
            T[j][i] = A[i][j];    
        }
    } 
}
void mat_multv (int m, int n, double** A, double* v, double* w){
    int i,j;
    for(i = 0;i<m;i++){
        w[i] = 0;
        for(j = 0;j<n;j++){
            w[i] += v[j]*A[i][j];    
        }
    } 
}
void mat_multm (int m, int n, int q, double** A, double** B, double** C){
    int i,j,k;
    for(i = 0;i<m;i++){
        for(j = 0;j<q;j++){
            C[i][j] = 0;
            for(k = 0;k<n;k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    } 
    
}

