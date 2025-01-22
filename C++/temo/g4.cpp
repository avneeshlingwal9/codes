#include <iostream> 
using namespace std ; 
int main(){
    int n ,sm = 0  ,k = 1 ; 
    cout << "Enter the no. of terms till you want to do the sum : - "<< endl ; 
    cin >> n ;
    for ( k ; k < n+1 ; k++){
        if (k %2 != 0 ){
            sm+=k;
        }
        else {
            sm-=k;
        }
        
    }
    cout << "The sum of the series is : - " << sm << endl ; 
    return 0 ;
}