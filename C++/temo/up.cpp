#include <iostream>
using namespace std ;
int main(){
    string s ; 
    cout << "Enter the string : - " << endl ;
    getline(cin,s);
    char a ; 
    for(int i = 0 ; i < s.length(); i++){
        if(s[i]>91 && s[i]<123){
            s[i]= s[i]-32;

        }

        
        

    }
    cout << s << endl ;
}

