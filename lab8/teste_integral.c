#include<stdio.h>
#include<math.h>
#include"integral.h"
#define PI 3.14159265358979323
double f(double x){
    return cos(x)-2*sin(x);
}
double f1(double x){
    return x/sqrt(x*x + 9);
}
double f2(double x){
    return x*x*log(x);
}
double f3(double x){
    return x*x*sin(x);
}
int main(){
    int i;
    for(i=1;i<13;i++){
        double h = pow(10,-1*i);
        double f0 = derivada(f,h,0);
        double err = fabs(fabs(f0)-2.0);
        //valor correto da derivada = -2.0
        printf("%lf\t%lf\t%lf\n",h,f0,err);
    }
    /*
     para achar o h que minimiza o erro:
     E(h) = (h*h/6) * f'''(c) + emaq/h
     temos:
        emaq = 2^(-52), limite de double
        c = 0, que maximiza a funcao dentro do intervalo periodico
        f'''(x) = sin(x) + 2*cos(x)
     logo:
        h deve ser aproximadamente 6.9 * 10^-6
     */


    double f1_16,f2_16,f3_16,f1_32,f2_32,f3_32,f1_r,f2_r,f3_r;
    f1_r = 2.0;
    f2_r = 6.9986217091241;
    f3_r = 5.8696044010894;
    f1_16 = simpson(f1,0,4,16);
    f2_16 = simpson(f2,1,3,16);
    f3_16 = simpson(f3,0,PI,16);
    f1_32 = simpson(f1,0,4,32);
    f2_32 = simpson(f2,1,3,32);
    f3_32 = simpson(f3,0,PI,32);
    printf("simpson\n");
    printf("%lf %lf %lf\n",f1_16,f2_16,f3_16);
    printf("%lf %lf %lf\n",f1_32,f2_32,f3_32);
    printf("%lf %lf %lf\n",f1_r,f2_r,f3_r);
    f1_16 = pontomedio(f1,0,4,16);
    f2_16 = pontomedio(f2,1,3,16);
    f3_16 = pontomedio(f3,0,PI,16);
    f1_32 = pontomedio(f1,0,4,32);
    f2_32 = pontomedio(f2,1,3,32);
    f3_32 = pontomedio(f3,0,PI,32);
    printf("pontomedio\n");
    printf("%lf %lf %lf\n",f1_16,f2_16,f3_16);
    printf("%lf %lf %lf\n",f1_32,f2_32,f3_32);
    printf("%lf %lf %lf\n",f1_r,f2_r,f3_r);
}
