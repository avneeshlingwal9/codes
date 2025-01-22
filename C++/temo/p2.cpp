/* Q1:- Write a program to add two numbers inside the class . */

#include <iostream>
using namespace std;
class a  // Defining the class 
{public : 

    int x , y , z   ; // Defining variables 
    void add()  // Defining method add  
    { 
        cout << "Enter two numbers: - \n"; 
        cin >> x >> y ;
        z = x+y ;
        cout << "The sum is : - " << z << endl ;
    } 


};

int main(){ 
    a add1 ;   // Creating the object 
    add1.add();  // Using the method 
    return 0 ;
}
