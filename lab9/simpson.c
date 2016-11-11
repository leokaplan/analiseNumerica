#include<math.h>
double DoubleSimpson(double a, double b, double (*f) (double x), double* v){
    double c = (a+b)/2;
    double fa = f(a);
    double fb = f(b);
    double fc = f(c);
    double Scb = ((b-c)/12)*(fc+4*f((c+b)/2)+fb);
    double Sac = ((c-a)/12)*(fa+4*f((c+a)/2)+fc);
    double Sab = ((b-a)/6)*(fa+4*fc+fb);
    *v = Scb + Sac;
    return fabs(Sab - Scb - Sac); 
}
double AdaptativeSimpson(double a, double b, double (*f) (double x), double tol){
    double c = (a+b)/2;
    double v;
    if (DoubleSimpson(a,b,f,&v)<tol) return v;
    else return DoubleSimpson(a,c,f,&v) + DoubleSimpson(c,b,f,&v);
    
}
