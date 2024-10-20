#include <iostream>
using namespace std ; 
class Base{
    public :
    string ename ;
    int eid ;
    int cnum ;
    Base(){
        ename = "noname";
        eid = 0 ;
        cnum = 0 ;
    }
    virtual void  get(string s , int a , int b){}; // Using virtual function as we need to override in child class.
    virtual void display(){};

};
class Child :  public Base{
    public :
    string eaddress ;
    string department ;
    Child(){
        eaddress = "empty";
        department = "empty";
    }

    void get(string s , int a , int b){
        ename = s ;
        eid = a ;
        cnum = b ;
    }

    void display(){
        cout << "Employee name is " << ename << " and id is " << eid << " and  cnum is " << cnum << endl ;
    }

};

int main(){
    Base *b = new Child();
    b->get("h",23,45);
    b->display();

}