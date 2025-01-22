#include <iostream>
using namespace std ;
int main(){
    string s ; 
    int c = 0 ;
    cout << "Enter string : - " << endl ; 
    getline(cin,s);
    for(int i = 0 ; s[i]!= '\0' ; i++){
        c++ ;

    }
    cout << c << endl ;
}