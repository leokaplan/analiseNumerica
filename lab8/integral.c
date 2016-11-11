#include "integral.h"
double derivada(double(*f) (double x),double h, double x){
    return (f(x+h) - f(x-h))/(2*h);
}
double simpson(double(*f) (double x),double a, double b,int n){
    double h = (b-a)/n;
    double r = 0;
    double i;
    for(i=a;i<b;i+= h){
        r += (h/6)*(f(i)+4*f(i+0.5*h)+f(i+h));
    }
    return r;
}
double pontomedio(double(*f) (double x),double a, double b,int n){
    double h = (b-a)/n;
    double r = 0;
    double i;
    for(i=a;i<b;i+=h){
        r += (h)*f((2*i+h)/2);
    }
    return r;
}
