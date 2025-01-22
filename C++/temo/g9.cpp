#include <iostream>
using namespace std ;
int main(){
    int x ,y , temp ; 
    cout << "Enter first number:- "<< endl ;
    cin >> x ;
    cout << "Enter second number : - "<< endl ;
    cin >> y ; 
    temp = x ;
    x = y ;
    y = temp ;
    cout << "The first number now is : - " << x << endl ;
    cout << "The second number now is : - " << y << endl ;
    

}