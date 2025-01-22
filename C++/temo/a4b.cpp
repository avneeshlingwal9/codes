#include <iostream>
using namespace std ;
class Employee{
    private:
    static int count ;
    double salary ;
    string name ; 
    int emp_id ;
    public :
    Employee(double m , string n , int i){
        salary = m ; 
        name = n ;
        emp_id = i ;
        count++;
    }
    Employee(Employee &p){
        salary = p.salary;
        name = p.name;
        emp_id= p.emp_id;
        count++;
    }
    static int getcount(){
        return count ;

    }

    



};
int Employee::count = 0 ;
int main(){
    Employee e1(20000.0, "Anjali",12);
    Employee e2(e1);
    int a = Employee::getcount();
    cout << "Count of objects is : - "<< a; 
}