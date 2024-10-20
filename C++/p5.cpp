/*Q3:- Write a program to add two numbers using return keyword. */
#include <iostream>
using namespace std;
class a  // Defining class 
{public :

    int x , y    ;
    int  add()
    {
        cout << "Enter two numbers: - \n"; 
        cin >> x >> y ;
    
        return x+y ;  // Using return keyboard 

    } 


};

int main(){
    int sm ;  
    a add1 ;  // Creating the object 
    sm = add1.add(); // Using the method 
    cout << "The sum of the numbers is : - " << sm << endl ; 
    return 0 ;
}
