#include <iostream>
using namespace std;
class Employee{
    public :
    int age ;
    string name ;
    Employee(){
        cout << "Enter the name of the student " << endl ;
        getline(cin,name );
        cout << "Enter the age of the student " << endl ;
        cin >> age ;
        cout << "Constructor executed " << endl ;
    }
    void display(){
        cout << "The name of the employee is " << name << " and age is " << age << endl ;
    }
    ~Employee(){
        cout << "Destructor executed. "  << endl ;
    }

};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    Employee e ;
    e.display();
}

