#include <iostream>
#include <process.h>
using namespace std ; 
int main(){
    int n ;
    cout << "Enter a number : - "<< endl ;
    cin >> n ;
    for ( int i = 2 ; i < n/2 ; i++){
        if ( n %i == 0 ){
            cout << "The entered number is not prime ." << endl ; 
            exit(0);
        }
    }
    cout <<"The entered number is prime . " << endl ; 

}