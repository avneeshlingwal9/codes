#include <iostream>
using namespace std ;
class Employee{
    public :
    string name ;
    int* age ;
    Employee(string aname , int p){
        this->name = aname ;
        *age= p ;
    }
    ~Employee(){
        cout << "Destructor executed " << endl ; 
    }
    void display(){
        cout << "Name of the employee is " << this->name <<" and age is " << *age << endl ; 
    }
};
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    int a  ;
    string s ;
    cout << "Enter the name of the employee :- " << endl ;
    getline(cin,s);
    cout << "Enter the age of the employee: - " << endl ; 
    cin >> a ; 
    Employee e(s,a);

    e.display();


}
