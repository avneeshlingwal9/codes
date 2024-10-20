/* Q4: - Write a program to add two numbers using user input in main method and
print results without using thord variable. */

#include <iostream>
using namespace std;
class a  // Defining class 
{public : 
    int add(int x, int y)
    {
        return x+y ;  // Returning the sum of two numbers 
    } 


};

int main(){
    int m,n ; 
    cout << "Enter two numbers : - \n";
    cin >> m >> n ;  // Taking input 
    a add1 ;  // Creating an object 
    cout << "The sum of two numbers is : - " << add1.add(m,n) << endl ;
    return 0 ;
}
