#include <iostream>
using namespace std;
class A{
    public :
    int num = 10 ; 
};
class B{
    public :
    int num = 20 ;
};
class C : public A ,B{
    public :
    int num = 30 ; 
    void display(){
        cout << "Value of number in A " << A::num << endl ;
        cout << "Value of number in B " << B::num << endl ;
        cout << "Value of number in C " << num << endl ;
    }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ;
    cout << "Accessing variables of same name of different classes " << endl ; 
    C c ;
    c.display();

}