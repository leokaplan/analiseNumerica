#include "mmq.h"
#include "matriz.h"
#include "IO.h"

#include <stdlib.h>
#include <math.h>

int main(){
    double** A = mat_cria(5,3); 
    A[0][0] = 3;
    A[1][0] = 4;
    A[2][0] = -3;
    A[3][0] = 1;
    A[4][0] = -2;
    A[0][1] = -1;
    A[1][1] = 1;
    A[2][1] = 2;
    A[3][1] = 1;
    A[4][1] = 0;
    A[0][2] = 2;
    A[1][2] = 0;
    A[2][2] = 1;
    A[3][2] = 5;
    A[4][2] = 3;

    double* b = (double*)malloc(5*sizeof(double));
    b[0] = 10;
    b[1] = 10;
    b[2] = -5;
    b[3] = 15;
    b[4] = 0;

    double* x = mmq(5,3,A,b);
    print(1,3,&x,"x:"); 
    printf("erro: %lf\n",norma2(5,3,A,b,x));
    /*x == 3 1 2*/

    double** A2 = mat_cria(5,4);
    A2[0][0] = 4;
    A2[1][0] = -2;
    A2[2][0] = 1;
    A2[3][0] = 1;
    A2[4][0] = 3;
    A2[0][1] = 2;
    A2[1][1] = 3;
    A2[2][1] = 3;
    A2[3][1] = 0;
    A2[4][1] = 1;
    A2[0][2] = 3;
    A2[1][2] = -1;
    A2[2][2] = -4;
    A2[3][2] = 1;
    A2[4][2] = 3;
    A2[0][3] = 0;
    A2[1][3] = 1;
    A2[2][3] = 2;
    A2[3][3] = -1;
    A2[4][3] = -2;
    
    double* b2 = (double*)malloc(5*sizeof(double));
    b2[0] = 10;
    b2[1] = 0;
    b2[2] = 2;
    b2[3] = 0;
    b2[4] = 5;

    double* x2 = mmq(5,4,A2,b2);
    print(1,4,&x2,"x:"); 
    printf("erro: %lf\n",norma2(5,4,A2,b2,x2));

    double** A3 = mat_cria(8,2);
    double* b3 = (double*)malloc(8*sizeof(double));
    double* c3 = (double*)malloc(8*sizeof(double));
    c3[0] = 8.0;
    c3[1] = 12.3;
    c3[2] = 15.5;
    c3[3] = 16.8;
    c3[4] = 17.1;
    c3[5] = 15.8;
    c3[6] = 15.2;
    c3[7] = 14.0;
    int i;
    for(i=0;i<8;i++){
        A3[i][0] = 1;
        A3[i][1] = i+1;
        b3[i] = log(c3[i])-log(i+1);
    }
    double* x3 = mmq(8,2,A3,b3);
    print(1,2,&x3,"x3:"); 
    printf("erro: %lf\n",norma2(8,2,A3,b3,x3));
    double t;
    for(t=0;t<16;t+=0.1){
        printf("%lf,%lf\n",t,exp(x3[0])*t*exp(x3[1]*t));
    }
    
    return 0;
}
