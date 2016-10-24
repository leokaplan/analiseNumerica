/*
Autor: Leonardo Kaplan 1212509
*/
#ifndef _MATRIZ
/*
Este modulo define um tipo para representacao de matrizes dinamicas.  
A matriz e representada por um vetor de ponteiros, onde cada elemento aponta para o vetor linha.
*/
#define _MATRIZ
/*cria dinamicamente uma matriz de dimensao (m,n), onde m representa o numero de linhas e n representa o numero de colunas*/
double** mat_cria (int m, int n);
/*libere a memoria de uma matriz previamente criada. A funcao recebe o numero de linhas m da matriz*/
void mat_libera (int m, double** A);
/*preenche a transposta de uma dada matriz.  A funcao recebe as dimensoes (m,n) da matriz original,  a matriz original A e a matriz transposta a ser preenchida T com dimensao (n,m)*/
void mat_transposta (int m, int n, double** A, double** T);
/*recebe uma matriz e um vetor e preencha um outro vetor com o resultado da multiplicacao da matriz pelo vetor.  A funcao recebe a dimensao (m,n) da  matriz  e  assume  que  o  primeiro  vetor v tem  dimensao n e  o  vetor  resultado w tem dimensao m*/
void mat_multv (int m, int n, double** A, double* v, double* w);
/*calcula  a  multiplicacao  entre  duas  matrizes: C = AB. A funcao recebe as dimensoes (m,n) e q e as matrizes A(m,n) , B(n,q) e C(m,q), preenchendo C*/
void mat_multm (int m, int n, int q, double** A, double** B, double** C);

#endif
