double bissecao(double a,double b, int p, double (*f) (double x)){
    double errmax = 0.5*pow(10,-p);
    double e;
    for(e = (b-a)/2.0;e>=errmax;e = e/2.0){
        if(f(a+b/2.0) < e) return e;
    }
}

double pontofixo(double x0,double epsilon, double (*g)(double x)){

}

