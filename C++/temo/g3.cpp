#include <iostream>
using namespace std ;
int main(){
    double  temp,fahr ; 
    cout << "Enter the temperature you are willing to convert : - "<< endl ; 
    cin >> temp ;
    fahr = (9.0/5.0*temp)+32 ;
    cout << "The temperature in Fahrenheit is : - " << fahr << endl ;
    return 0 ; 
}