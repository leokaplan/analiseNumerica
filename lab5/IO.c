#include "IO.h"
#include<stdio.h>

void print(int m, int n, double** mat,char* label){
    int i,j;
    printf("%s (%d,%d)\n",label,m,n);
    for(i = 0;i<m;i++){
        for(j = 0;j<n;j++){
            printf("%.2f\t",mat[i][j]);
        }
        printf("\n");
    } 
}
