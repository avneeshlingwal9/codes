#include <iostream>
using namespace std; 
double sinr(int x , int n ){
    static double p = x, f = 1;
    double r; 
    if(n == 0 ){
        return x; 
    }
    r = sinr(x, n - 1);
    p *= -1*x * x;
    f *= (2 * n+1 )*(2 * n );
    

    return r + (p / f);
}
double sino(int x , int n ){
    static double r = 1; 
    if(n==0){
        return r; 

    }
    r = 1 - r* (x *x) / ((2*n)*(2*n + 1 ));
    return sino(x, n - 1);
    
}
double sinl(int x , int n){
    double s=x ;
    double p = x, f = 1; 
    for (int i = 1; i <= n; i++){
        p *= -x * x;
        f *= (2 * i) * (2*i + 1 );
        s += (p / f);
    }
    return s;
}

int main(){
    cout << "Value of sin function using recursion is : " << sinr(9,10) << endl;
    cout << "Value of sin function using optimal recursion is: " << sino(9, 10) << endl;
    cout << "Value of sin function using loops is: " << sinl(9, 10) << endl;
}