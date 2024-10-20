/*Q2: - Write a program to find minimum of two numbers using 
method outside class.*/
#include <iostream>
using namespace std ; 
class m  // Defining class 
{ 
    public : 
    int x , y ; // Declaring variables . 
    void min();
};
void m ::min(){ // Defining the method out the class. 
    cout << "Enter two numbers : - " << endl ; 
    cin >> x >> y ; 
    if ( x < y ){
        cout << "The smaller number is : - " << x << endl ;   
    }
    else {
        cout << "The smaller number is : -  " << y << endl ; 
    }
}
int main(){
    m min1;  // Creating object     
    min1.min(); // Using the method 
    return 0 ; 
}
