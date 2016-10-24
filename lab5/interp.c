#include "interp.h"
#include "matriz.h"
#include <math.h>
#include <stdlib.h>
void swap(double* a, double*b){
    double c = *a;
    *a = *b;
    *b = c;
}
double** fatoracao(int n, double** A){
    double** P = mat_cria(n,n);
    int i,j,k,p;
    for(i=0;i<n-1;i++) P[i][i]=1;
    for(j=0; j<n-1;j++){
        /*pivotamento*/
        p = j;
        for(k=j+1;k <= n-1;k++){
            if( fabs(A[k][j]) > fabs(A[p][j]) ){
                p = k;
            }
        }
        for(k=j;k < n;k++){
            swap(&A[j][k],&A[p][k]);
            swap(&P[j][k],&P[p][k]);
        }
    } 
    for(j=0; j<n-1;j++){
        for(i=j+1;i<=n-1;i++){
            double f = A[i][j]/A[j][j];
            A[i][j] = f;
            for(k=j; k<=n-1;k++){
                A[i][k] -= A[j][k]*f;
            }
        }
    }
    return A;    
};
double* substituicao(int n, double** A, double** P, double* b){
    int i,j;
    double* x = (double*)malloc(n*sizeof(double));
    double* y = (double*)malloc(n*sizeof(double));
    double* Pb = (double*)malloc(n*sizeof(double));
    mat_multv(n,n,P,b,Pb);
    mat_multm(1,n,n,&Pb,A,&y);
     
    
    for(i=n-1; i >= 0;i--){
        double s = 0;
        for(j=i+1;j<=n-1;j++){
            s += A[i][j]*x[j];
        }
        x[i] = (y[i]-s)/A[i][i];
    }
    return x;
}
double* interpola(int n, double* px, double* py){
    double** A = matcria(n,1);


}

double* avalia(int n, double*c, double x){

}




double L(int k,int n,double x, double* px){
    double l = 1;
    int i;
    for(i=0;i<n-1;i++){
        if(i == k) continue;
        l *= (x-px[i])/(px[k]-px[i]);
    }
    return l;
}
double lagrange(int n, double* px, double* py, double x){
    double p = 0;
    int i;
    for(i=0;i<n;i++){
        p += py[i]*L(i,n,x,px);
    }
    return p;
}
