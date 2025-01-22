#include <iostream>
#include <fstream>
using namespace std ;
int main(){
    ifstream g ;
    string m ;  
    g.open("h.txt",ios::in);
    while (g){
        getline(g,m) ; 
        if ( m == "-1"){
            break ;}
        else {
        cout << m  ;}
    }
    g.close();

}