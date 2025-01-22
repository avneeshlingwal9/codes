#include <iostream>
using namespace std ;
int main(){
    string str[5], temp ;

    for(int i = 0 ; i < 5 ; i++){
        cout << "Enter a word : - "  << endl ; 
        getline(cin , str[i]);
    }
    cout << "Original string is : - " << endl ; 
    for(int i = 0 ; i < 5 ; i++){
        cout << str[i] << " " ; 
    }
    cout << endl ;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(str[j]> str[i]){
                temp = str[i];
                str[i]= str[j];
                str[j] = temp ;
            }
        }
    }
    cout << "String in alphabetical order is : - " << endl ; 
    for(int i = 0 ; i < 5 ; i++){
        cout << str[i] << " "; 
    }
}