#include <stdio.h>
int fib[30];
int fibr(int n){
    if(n<=1){
        return n;
    }
    return fibr(n - 1) + fibr(n - 2);
}
int fibo(int n){
    if(n<=1){
        fib[n] = n;
        return n; 
    }
    else{
    if(fib[n-1]==-1){
        fib[n - 1] = fibo(n - 1);
    }
    if(fib[n-2]==-1){
        fib[n - 2] = fibo(n - 2);
    }
    fib[n] = fib[n - 1] + fib[n - 2];
    return fib[n];
    }
}
int fibi(int n){
    int t0 = 0, t1 = 1, s = 0; 
    if(n <=1){
        return n;
    }
    for (int i = 1; i < n; i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s; 
    }
    return s; 
}

int main(){
    

    for (int i = 0; i < 30; i++){
        fib[i] = -1;
    }
    
        printf("Fibbonacci series using optimized recursion %d ", fibo(8));
        printf("\nFibbonacci series using plain recursion %d ", fibr(8));
        printf("\nFibbonacci series using loops %d ", fibi(2));
    return 0;
}