/* Q3: - Write a program to find minimum of two numbers using parameterization*/
#include <iostream>
using namespace std ; 
class m  // Defining class 
{   private :
    int x , y ;  // Declaring variables . 
    public : 
    // Paramaterization 
    int getx(){
        cout << "Enter a number : - " << endl ; 
        cin >> x ; 
        return x ;
        }
    int gety(){
        cout << "Enter a number : - " << endl ; 
        cin >> y ;
        return y ;
    }
    int min(){
        if (x < y){
            return x ; 
        }
        else {
            return y ; 
        }
    }
    void display(){
        cout << "The smaller number is : - " << min() << endl ; 
    }   
};
int main(){
    m min1;  // Creating object  
    // Using the method 
    min1.getx();
    min1.gety();
    min1.min();
    
    min1.display();
    return 0 ; 
}
