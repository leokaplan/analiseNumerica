#include "raiz2.h"
#include <math.h>
int NR (double x0, int p, double (*f) (double x), double (*fl) (double x), double* r){
    double y;
    double yl;
    double tol = 0.5*pow(10,-1*p);
    int iter;
    int maxiter = 10;
    double x1;
    for(iter=1;iter<maxiter;iter++){
        //if(fabs(yl)<eps){
        //    return//denominador mto pequeno
        //}
        y = f(x0);
        yl = fl(x0);
        x1 = x0 - y/yl;
        if(fabs(x1-x0)<=tol*fabs(x1)){
            *r = x1; 
            return iter;
        }
        x0 = x1;
    }
    return 0;
}


int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r){
    int iter;
    int maxiter = 50;
    double tol = 0.5*pow(10,-1*p);
    for(iter=1;iter<maxiter;iter++){
        double f0,f1,f2;
        f0 = f(x0);
        f1 = f(x1);
        f2 = f(x2);
       /* 
        math.gmu.edu/~memelian/teaching/Spring10/notes/MATH685_Sp10_lec8.ppt
        */
        double u,v,w;
        u = f1/f2;
        v = f1/f0;
        w = f0/f2;
        double p = v*(w*(u-w)*(x2-x1)-(1-u)*(x1-x0));
        double q = (w-1)*(u-1)*(v-1);
        /*
        double c = x1 +p/q;
        */
        double a[3][3] = {
            {f0*f0,f0,1},
            {f1*f1,f1,1},
            {f2*f2,f2,1}
        };
        double ac[3][3] = {
            {f0*f0,f0,x0},
            {f1*f1,f1,x1},
            {f2*f2,f2,x2}
        };
        double detA = 0;
        double detAc = 0;
        int i;
        for(i=0;i<3;i++){
            detA += (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
        }
        for(i=0;i<3;i++){
            detAc += (ac[0][i]*(ac[1][(i+1)%3]*ac[2][(i+2)%3] - ac[1][(i+2)%3]*ac[2][(i+1)%3]));
        }
                
        /*
        */
        double c = detAc/detA;   
        /*
        
        */
        double fc = f(c);
        if(fabs(fc)<=tol){
            *r = fc; 
            return iter;
        }
        x0 = x1;
        x1 = x2;
        x2 = c;
    }
    return 0;
}
