#include <iostream>
using namespace std ;
class Person{
    public :
    string address ; 
    int phone ;
    Person(){
        cout << "Enter details : " << endl ;
        cout << "Enter the address :" << endl ;
        getline(cin, address);
        cout << "Enter phone number: " << endl ;
        cin >> phone ;
        cin.ignore();
    }
};
class Employee : public Person {
    public :
    int eno ; 
    string ename ;
    Employee(){
        cout << "Enter the employee number: " << endl ;
        cin >> eno ;
        cin.ignore();
        cout << "Enter the name : " << endl ;
        getline(cin,ename);
    }
};
class Manager : public Employee{
    public :
    string designation ; 
    string deptname ;
    double salary ;
    Manager(){
        cout << "Enter designation: " << endl ;
        getline(cin, designation);
        cout << "Enter department name: " << endl ;
        getline(cin, deptname);
        cout << "Enter salary: " << endl;
        cin >> salary ;
        cin.ignore();
    }
    void display(){
        cout << "Name of the employee is " << ename << endl ;
        cout << "Department is: " << deptname << endl ; 
        cout << "Salary is : " << salary << endl; 
        cout << "Designation is " << designation << endl ;
        cout << "Employee number is : " << eno << endl ;
        cout << "Address is : " << address << endl ;
        cout << "Phone number is: " << phone << endl;      }
};

int main(){
    int n ; 
    cout << "Enter the number of managers you want: " << endl ;
    cin >> n ; 
    cin.ignore();
     
    Manager arr[n];
    int highest = arr[0].salary ; // Finding index and value of the manager with highest salary .
    int index  = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i].salary > highest){
            highest = arr[i].salary ;
            index = i ; 
        }
    }
    arr[index].display();
}