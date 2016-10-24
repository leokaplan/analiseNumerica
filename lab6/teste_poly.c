#include<stdio.h>
#include<math.h>
#define PI 3.14159265359
#include "poly.h"
double quadrante(double a){
    if(a<0) a += 2*PI;
    if(a>=PI) a = 2*PI-a;
    if(a>=PI/2.) a = PI - a;
    return a;
}
int fat(int n) 
{ 
    int r = 1; 
    int i;
    for (i=2; i<=n; i++) 
        r *= i; 
    return r; 
} 
int main(){
    int n = 6;
    double _a = 0.;
    double _b = PI/2.;
    Sample* s = Chebyshev(n, _a,_b, cos);
    int j;
    double i;
    /*
    for(j=0;j<n;j++){
        printf("%lf %lf\n",s->x[j],s->y[j]);
    }
    Sample* s = malloc(sizeof(Sample));
    s->n = 4;
    s->x = (double*)malloc(n*sizeof(double));
    s->y = (double*)malloc(n*sizeof(double));
    s->x[0] = -1;
    s->x[1] = 0;
    s->x[2] = 1;
    s->x[3] = 2;
    s->y[0] = 3;
    s->y[1] = -4;
    s->y[2] = 5;
    s->y[3] = -6;
    */
    double* b = NewtonCompute(s);
    /*
    for(j=0;j<4;j++){
        printf("%lf\n",b[j]);
    }
    */
    for(i=-2*PI;i<2*PI;i+=0.1){
        double err = (pow(((_b-_a)/2.),n)/pow(2,n-1))*(pow(cos(i),n)/fat(n));
        double a = NewtonEval(s,b,quadrante(i));
        if(fabs(i)>=PI/2. && fabs(i)<=3*PI/2.) a =-a;
        double b = cos(i);
        if(fabs(a-b)>err) printf("%lf %lf\n",fabs(a-b),err);
        
    }

    
}
