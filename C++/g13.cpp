#include <iostream>
using namespace std ;
struct employee {
    int employee_no ;
    string name ; 
    double salary ; 


};
int main(){
employee e_1 ; 
cout << "Enter the name of the employee : - " << endl ;
cin >> e_1.name ;
cout << "Enter the employee number of the employee : - " << endl ;
cin >> e_1.employee_no ;
cout << "Enter the salary of the employee : - " << endl ;
cin >> e_1.salary ; 
cout << "The name of the employee is " << e_1.name << " and employee number of " << e_1.name << " is " << e_1.salary << " and the salary of " << e_1.name << " is "<< e_1.salary << " ." << endl ;

return 0 ;
}
