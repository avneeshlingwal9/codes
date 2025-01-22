/* Q2:- Write a program to add two values using method outside the class . */

#include <iostream>
using namespace std;
class a  // Defining class 
{public :

    int x , y , z   ;
    void add();
};
void a::add(){  // Defining the method outside the class 
    int x,y,z  ;
    cout << "Enter the numbers : - " << endl ; 
    cin >> x >> y ; 
    z = x+y ;
    cout << "The sum of the numbers is : - " << z << endl  ; 
}

int main(){ 
    a add1 ;  // Creating method 
    add1.add(); // Using the method 
    return 0 ;
}
