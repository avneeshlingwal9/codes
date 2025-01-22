#include <iostream>
using namespace std ;
int main(){
    int x , rem , rev = 0 ;    
    cout << "Enter a number : - \n" ;
    cin >> x ;
    if(x >=0 ){
        while ( x  != 0 ){
            rem = x%10 ; 
            rev = rev*10+rem ;
            x /=10 ; 
        }
        cout << "The reverse of the number is : - " << rev ;
    }
    else {
        while ( x != 0 ){
            rem = x%10;
            rev = rev*10 + rem ;
            x/=10;
        }
        cout << "The reverse of the number is : - " << 0-rev << endl ; 
    } 
    return 0 ;
}