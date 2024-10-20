#include <stdio.h>
int factr(int n ){
    if(n==0){
        return 1; 
    }
    return factr(n-1)*n;
}
int facti(int n){
    int prod = 1;
    for (int i = 1; i <= n; i++){
        prod *= i;
    }
    return prod;
}
int main(){
    int n = 5;
    int f1 = factr(n), f2 = facti(n);
    printf("Factorial using recursion is %d ", f1);
    printf("\nFactorial using iteration is %d ", f2);
    return 0;
}
