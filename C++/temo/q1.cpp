#include <iostream>
using namespace std ; 
void sw(int* a , int* b){
    int t = *a ; 
    *a = *b ;
    *b = t ; 
}
int main(){
    int a = 10 , b = 5 ; 
    sw(&a , &b);
    cout << a << " " << b << endl ;
}