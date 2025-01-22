#include <iostream>
#include <fstream>
using namespace std ;
int main(){
    int count = 0 ; 
    ofstream k ; 
    k.open("hlo.txt");
    string l ; 
    while (k){
        cout << "Enter the line :- " << endl ;
        getline(cin,l);
        if ( l == "-1"){
            break ;
        }
        k << l << endl ; 
         
        }
    k.close();
    ifstream nm ; 
    nm.open("hlo.txt");
    int countVowels(){
        while(nm,l){
            
        }

    }




    

    
    
    
    



}