#include <iostream>
using namespace std ;
class Employee{
    public :
    int salary ;
    Employee(int asalary){
        salary = asalary ;
    }
    Employee(){
        salary = 0 ;
    }

   
    void display(){
        cout << "Salary of the employee is " << salary << endl ;
    }
};
Employee operator+(const Employee& roh , const Employee& vir){
        Employee e3 ;
        e3.salary = roh.salary + vir.salary ;
        return e3 ;

    }

int main(){
    Employee e1(20000);
    Employee e2(40000);
    Employee e3 = e1+e2 ;
    e1.display();
    e2.display();
    e3.display();
}