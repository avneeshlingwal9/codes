/* Q1: - Write a program to find minimu of two numbers*/
#include <iostream>
using namespace std ; 

class m  // Defining class 
{ 
    public : 
    int x , y ; // Declaring variables . 
    void min(){
        cout << "Enter two numbers : - " << endl ; 
        cin >> x >> y ;
        if (x < y ){
            cout << "The smaller number is : - " << x <<endl ; 
        }
        else {
         cout << "The smaller number is : - " << y << endl ;
         }   
    }
};
int main(){
    m min1;  // Creating object     
    min1.min(); // Using the method 
    return 0 ; 
}
