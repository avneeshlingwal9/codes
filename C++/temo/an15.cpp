#include <iostream>
using namespace std;
class base{
    public :
  
    void display(){
        cout << "This is base class " << endl ;
    }
};
class in : public base {
   
    public :
    void display(){
        cout << "This is sub class " << endl ;
    }
};
int sunm(int a , int b){
    return a+b ;
}
int sunm(int a , int b , int c ){
    return a+b+c ;
}
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    cout << "Function overriding " << endl ;
    base ba ;
    in i ;
    ba.display();
    i.display();
    int a , b , c ;
    cout << "Enter three numbers :- " << endl ;
    cin >> a >> b >> c ;
    cout << "Function overloading " << endl ;
    cout << "Sum of two numbers is " << sunm(a,b) << endl ;
    cout << "Sum of three numbers is " << sunm(a,b,c) << endl ;
}
