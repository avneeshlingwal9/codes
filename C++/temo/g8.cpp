#include <iostream>
using namespace std ; 
int main(){
    int num1 ;
    cout << "Enter a number : - " << endl ;
    cin >> num1 ; 
    cout << "The factors of " << num1 << " is : - " << endl ;
    for ( int i = 1 ; i < num1 ; i++){
        if (num1%i == 0 ){
            cout << i << " " ; 
        }
    }
}