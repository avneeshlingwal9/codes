/* Q4: - Write a program to find minimum of two numbers using return keyword*/
#include <iostream>
using namespace std ; 
class m  // Defining class 
{   public :
    int x , y ;  // Declaring variables . 
    int min(){ // Defining function to return greater number 
        cout << "Enter two numbers :- " << endl ; 
        cin >> x >> y ; 
        if (x < y ){
            return x ;  // Using the return 
        }
        else {
            return y ; 
        }
    }

};
int main(){
    int z ; 
    m min1;  // Creating object  
    z = min1.min();
    cout << "The smaller number is : -  " << z << endl ; 
    return 0 ; 
}
