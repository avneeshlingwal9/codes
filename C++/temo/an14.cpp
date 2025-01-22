#include <iostream>
using namespace std;
class base{
    public :
    int a  = 10 ; 
    void show(){
        cout << "This is base class. " << endl ;
        cout << "Number a is " << a << endl ; 
    }

};
class A : virtual public base{
    public :
    int a = 20 ;
    

};
class B : virtual public base {
    public :
    int a = 30 ;

};
class C : public A ,B {

};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    C obj ; 
    obj.show();
}