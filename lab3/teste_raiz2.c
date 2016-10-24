#include <stdio.h>
#include <math.h>
#include "raiz2.h"

double f(double x){
    return cos(x)-x*x*x+x;
}
double fl(double x){
    return -sin(x)-3*x*x+1;
}

int main(){
    double r;
    int iter;
    int i,j,k;
    float result = 1.15961;  
    printf("NR\n");
    for(i=1;i<10;i++){
            iter = NR(i,6,f,fl,&r);
            if(iter != 0){
                if(r - result < 0.001)
                    printf(" ");
                else
                    printf("_");
                //printf("NR: %lf com %d iteracoes\n",r,iter);
            }
            else
                printf(".");
                //printf("NR nao convergiu ou atingiu maximo de iteracoes\n");
    }
    printf("\nIQI\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            for(k=0;k<10;k++){
                if(i==j||i==k||j==k) continue;
                iter = IQI(i,j,k,6,f,&r);
                if(iter != 0){
                    if(r - result < 0.001)
                        printf(" ");
                    else
                        printf("_");
                    //printf("IQI: %lf com %d iteracoes\n",r,iter);
                }
                else
                    printf(".");
                    //printf("IQI nao convergiu ou atingiu maximo de iteracoes\n");
            }
        }
    }
    printf("\n");
}
