#include <iostream> 
#include <string> 
using namespace std ;
int main(){
    string  name , place  ; 
    int age ; 
    cout << "Enter your name : - " << endl ;
    getline(cin,name);
    cout << "Enter your age : -  " << endl ; 
    cin >> age ; 
    cout << "Enter the name of the place : - " << endl ; 
    getline(cin,place);
    cout << "Your name is : - " << name << "And you live in : - " << place << endl ;
    return 0 ; 

}