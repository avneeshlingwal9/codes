#include <iostream>
using namespace std ;
class base{
    public :
    void display(){
        cout << "This is  non- virtual function of base class " << endl ; 
    }
    virtual void sh(){
        cout << "This is  virtual function of base class " << endl ;
    }

};
class in : public base {
    public :
    void display(){
        cout << "This is non-virtual function of derived class " << endl ;
    }
    virtual void sh(){
        cout << "This is virtual function of derived class " << endl ;
    }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    base* b ; 
    in  n ;
    b = &n ; 
    cout << "Use of virtual function " << endl ; 
    b->display();
    b->sh();

}