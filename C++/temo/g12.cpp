#include <iostream>
using namespace std ;
int main(){
    int n ; 
    cout << "Enter a number : - " << endl ; 
    cin >> n ;
    for ( int i = 1; i < n+1; i++){
        for ( int j = 0 ;  j < i ; j++){
            cout <<"*" ;
        }
        cout << endl ;
    }
    return 0 ; 
}