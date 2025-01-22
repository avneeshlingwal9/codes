#include <iostream>
using namespace std ;
int main(){
    cout << "Name :- Anushka Negi " << endl ;
    cout << "Section:- G1 " << endl; 
    cout << "Roll No. :- 11 " << endl ; 
    string a , b ,c ; 
    cout << "Enter two strings : - " << endl ;
    getline(cin,a);
    getline(cin,b);
    for(int i = 0 ; i < a.size(); i++){        
        for(int j =0 ; j < b.size(); j++){
            if(a[i] == b[j]){
                if(c.find(a[i]) == string::npos){
                c+=b[j];}

            }
        }
    }
    cout << "Common between two strings : - " << c << endl ; 


}
