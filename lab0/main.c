#include "IO.h"
#include "matriz.h"
#include <stdlib.h>
int main(){
    double** mat = mat_cria(2,3);
    mat[0][0] = 1.0;
    mat[0][1] = -1.0;
    mat[0][2] = 2.0;
    mat[1][0] = 0.0;
    mat[1][1] = -3.0;
    mat[1][2] = 1.0;
    double** mat2 = mat_cria(3,2);
    print(2,3,mat,"mat");
    mat_transposta(2,3,mat,mat2);
    print(3,2,mat2,"mat2");
    
    double* vet = (double*)malloc(3*sizeof(double));
    double* vet2 = (double*)malloc(2*sizeof(double));
    vet[0] = 2.0;
    vet[1] = 1.0;
    vet[2] = 0.0;
    print(1,3,&vet,"vet");
    mat_multv(2,3,mat,vet,vet2);
    print(1,2,&vet2,"vet2");
    /* esperado: 1.00	-3.00*/
    double** mat3 = mat_cria(3,3);
    double** mat4 = mat_cria(2,2);
    mat_multm(2,3,2,mat,mat2,mat4);
    print(2,2,mat4,"mat4");
    /* esperado:
    6.00	5.00	
    5.00	10.00	
    */
    mat_multm(3,2,3,mat2,mat,mat3);
    print(3,3,mat3,"mat3");
    /* esperado:
    1.00	-1.00	2.00	
    -1.00	10.00	-5.00	
    2.00	-5.00	5.00	
    */
    return 0;
}
