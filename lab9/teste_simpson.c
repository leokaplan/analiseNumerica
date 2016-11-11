#include<math.h>
#include<stdio.h>
#include"simpson.h"
double f1(double x){ return x/(sqrt(x*x+9));}
double f2(double x){ return exp(-(x*x)/2);}
double f3(double x){ return exp(-(x*x));}


int main(){
    double tol = pow(10,-7);
    printf("%lf\n",AdaptativeSimpson(0,1,f1,tol));
    printf("%lf\n",(1/sqrt(2*3.14159265359))*AdaptativeSimpson(-1,1,f2,tol));
    printf("%lf\n",(2/sqrt(3.14159265359))*AdaptativeSimpson(0,3,f3,tol));
    return 0;
}
