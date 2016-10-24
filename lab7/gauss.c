#include "gauss.h"
#include "IO.h"
#include <math.h>
void swap(double* a, double*b){
    double c = *a;
    *a = *b;
    *b = c;
}
void gauss(int n, double** A, double* b, double* x){
    int i,j,p,k;
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
        }
        swap(&b[j],&b[p]);
        /*gauss*/
        for(i=j+1;i<=n-1;i++){
            double f = A[i][j]/A[j][j];
            for(k=j; k<=n-1;k++){
                A[i][k] -= A[j][k]*f;
            }
            b[i] -= b[j]*f;
        }
    } 
    /*
     print(n,n,A,"gauss");
     */

    /*regressao*/
    for(i=n-1; i >= 0;i--){
        double s = 0;
        for(j=i+1;j<=n-1;j++){
            s += A[i][j]*x[j];
        }
        x[i] = (b[i]-s)/A[i][i];
    }
}
