#include <stdio.h> 
double er(int x , int n ){
    static double
     p = 1, f = 1;
    double r;
    if(n==0){
        return 1;
    }
     r = er(x, n - 1);
    p *= x;
    f *= n;
    return r + (p / f);
}
double ero(int x , int n){
    static double s = 1.0; 
    if(n == 0){
        return s; 
    }
    s = 1 + x*s/n ;
    return ero(x, n - 1);
}
double el(int x , int n){
    double s = 1.0;
    for (; n > 0; n--)
    {
        s = 1 + x*s/n;
    }
    return s;
}
double eul(int x, int n ){
    double s = 1;
    double num = 1;
    double den = 1;
    for (int i = 1; i <= n; i++ ){
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main(){
    printf("Taylor series using recursion %lf ", er(2,110) );
    printf("\nTaylor series using more optimized recursion %lf ", ero(2, 110));
    printf("\nTaylor series using loops %lf ", el(2, 110));
    printf("\nTaylor series using loops %lf ", eul(2, 110));
    

    return 0; 
}