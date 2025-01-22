#include <iostream>
using namespace std ;
namespace n1{
    int a = 10 ; 
    void showa(){
        cout << "Value of a in First namespace :- " << a << endl ;
    }
}
namespace n2{
    int a = 20 ;
    void showa(){
        cout << "Value of a in Second namespace :- "<< a << endl ;
    }
}
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    n1::showa();
    n2::showa();
}