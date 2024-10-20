#include <stdio.h> 
int powr(int m , int n ){
    if(n==0 ){
        return 1;
    }
    return m * powr(m, n - 1);
}
int powi(int m , int n ){
    int e=1;
    for (int i = 0; i < n; i++){
        e *= m; 
    }
    return e; 
}
int powo(int m , int n ){
if(n==0){
    return 1;
}
if(n%2 == 0){
    return powo(m * m, n / 2);
}
return m * powo(m * m, (n - 1) / 2);
}
int main(){
    int m = 2, n = 9;
    printf("From recursion  %d ", powr(m, n));
    printf("\nFrom optimized recursion %d ", powo(m, n));
    printf("\nFrom iteration  %d ", powi(m,n));

    return 0; 
}