#include <stdio.h>
int factn(int n){
    if(n ==0){
        return 1;

    }
    return n * factn(n - 1);
}
int com(int n , int r){
    int t0= 0 , t1=0, t2=0;
    t0 = factn(n);
    t1 = factn(n - r);
    t2 = factn(r);
    return t0 / (t1 * t2);
}
int comr(int n, int r){
    if(r==0 || n == r){
        return 1;
    }
    return comr(n - 1, r - 1) + comr(n - 1, r);
}
int main(){
    printf("Combinations using factorial %d ", com(5, 2));
    printf("\nCombination using recursion %d ", comr(5, 2));

    return 0; 
}