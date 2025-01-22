/* Q3:- Write a program to add two numbers using parameterised class. */

#include <iostream>
using namespace std;
class a  // Defining the class 
{   private : 
    int a , b ,c; // Declaring the variables private 
    public : 
    // Parameterization of class by defining different functions in the class 
        int geta(){ 
            cout << "Enter a number : - " << endl ; 
            cin >> a ;
            return a ;
    }
        int getb(){
            cout << "Enter another number : - " << endl ; 
            cin >> b ; 
            return b ; 
    }
        int add(){
            c  = a + b ;
            return c ; 
        }
        void print(){
            cout << "The sum of the numbers is : - " << add() << endl ; 
        }
};

int main(){ 
    a add1 ;   // Creating the object 
    //Using different methods defined in the class . 
    add1.geta();
    add1.getb();
    add1.add();
    add1.print();
    return 0 ;
}
