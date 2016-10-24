#include "poly.h"
#include<math.h>
#include<stdlib.h>

struct sample{
    int n;
    double* x;
    double* y;
};

Sample* Chebyshev(int n, double a, double b, double (*f) (double x)){
    Sample* r = (Sample*)malloc(sizeof(Sample));
    double* x = (double*)malloc(n*sizeof(double));
    double* y = (double*)malloc(n*sizeof(double));
    r->n = n;
    r->x = x;
    r->y = y;
    int i;
    for(i=0;i<n;i++){
        double I = ((2.*i+1.)*PI)/(2.*n);
        r->x[i] = (b+a)/2. + ((b-a)/2.)*cos(I);
        r->y[i] = f(r->x[i]);
    }
    return r;
}
double* NewtonCompute(Sample* s){
    double* b = (double*)malloc(s->n*sizeof(double));
    int i,j;
    for(i=0;i < s->n ;i++){
        b[i] = s->y[i];
    }

    for(i=1;i < s->n ;i++){
        for(j=s->n-1;j>=i;j--){
            b[j] = (b[j] - b[j-1]) / (s->x[j] - s->x[j-i]);
        }
    }
    return b;

}
double NewtonEval(Sample* s, double* b, double x){
    double y = b[s->n-1];
    int i;
    for(i= s->n - 2;i >=0 ;i--){
        y = b[i] + (x - s->x[i])*y;
    }
    return y;
}
