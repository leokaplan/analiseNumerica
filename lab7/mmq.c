#include "mmq.h"
#include "IO.h"
double* mmq(int m, int n, double** A, double* b){
    double** At = mat_cria(n,m);
    mat_transposta(m,n,A,At);
    //print(m,n,A,"A"); 
    //print(n,m,At,"At"); 
    //print(1,n,&b,"b"); 
    double** bl = mat_cria(1,n);
    mat_multv(n,m,At,b,*bl);
    //print(1,n,bl,"bl"); 
    double** AtA = mat_cria(n,n);
    mat_multm(n,m,n,At,A,AtA);
    //print(n,n,AtA,"AtA"); 
    double** x = mat_cria(1,n);
    gauss(n, AtA,*bl,*x);
    //print(1,n,x,"x"); 
    return *x;
}
#include<math.h>
double norma2(int m, int n, double** A, double* b,double* x){
    double e = 0;
    double** Ax = mat_cria(1,m);
    mat_multv(m,n,A,x,*Ax);
    //print(1,5,Ax,"Ax");
    //print(1,5,&b,"b");
    int i;
    for(i=0;i<m;i++){
        e += (b[i]-Ax[0][i])*(b[i]-Ax[0][i]);
    }
    return sqrt(e);
}

