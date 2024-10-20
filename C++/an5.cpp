#include <iostream>
using namespace std ;
int factorialrecursion(int n ){
    if(n == 0){
        return 1 ;
    }
    return n*factorialrecursion(n-1);
}
inline int cub(int n){ return n*n*n ;}
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    int a , b ; 
    cout << "Enter a number for recursion : - " << endl ; 
    cin >> a ;
    cout << "Recursion function " << endl ;
    cout << "The factorial of the number is :- " << factorialrecursion(a)  << endl ;
    cout << "Enter a number to cube  :- " << endl ;
    cin >> b ;
    cout << "Inline function " << endl ;
    cout << "The cube of the number is :- " << cub(b) << endl ; 


}




































































