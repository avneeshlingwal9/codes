#include <iostream>
using namespace std ; 
int factr(int n );
int facti(int j );
int main(){
    int n ;
    cout << "Enter the number: - "<< endl ;
    cin >> n ;
    cout << "The factorial of the number from recursion is : - " << factr(n)<< endl ; 
    cout << "The factorial of the number from iteration : - "<< facti(n)<< endl ;
    return 0 ;
}
int factr( int n ){
    if (n>1){
        return n*factr(n-1);
    }
    else {
        return 1 ;
    }
}
int facti(int j){
    int prcd = 1 ; 
    for(int i = 1 ; i<j+1 ; i++)
    {
        prcd*=i;
    }
    return prcd ; 
}