#include "matriz.h"
#include "gauss.h"
#include "IO.h"
#include <stdlib.h>

int main(){
    double** A = mat_cria(3,3); 
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = -1;
    A[1][0] = 2;
    A[1][1] = 1;
    A[1][2] = -2;
    A[2][0] = -3;
    A[2][1] = 1;
    A[2][2] = 1;

    double* b = (double*)malloc(3*sizeof(double));
    b[0] = 3;
    b[1] = 3;
    b[2] = -6;

    double* x = (double*)malloc(3*sizeof(double));
    /*print(3,3,A,"pre"); */
    gauss(3,A,b,x);
    print(1,3,&x,"pos"); 
    /*x == 3 1 2*/




    double** A2 = mat_cria(6,6); 
    int i,j;
    for(i=0;i<=5;i++){
        A2[5-i][i] = 0.5;
        A2[i][i] = 3;
        if(i<5)A2[i+1][i] = -1;
        if(i>0)A2[i-1][i] = -1;
    } 
    /*
    print(6,6,A2,"pre");
    */
    double* x2 = (double*)malloc(8*sizeof(double));
    double b2[6] = {2.5,1.5,1,1,1.5,2.5};
    gauss(6,A2,b2,x2);
    print(1,6,&x2,"pos"); 
    /*x == {1,1,1,1,1,1}*/
    
    
    
    return 0;
}
