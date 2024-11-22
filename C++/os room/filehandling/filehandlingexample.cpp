#include <iostream>
#include <fstream>
using namespace std ;
int main(){
    ofstream f;
    f.open("anushka.txt");
    string l ;
    while(f){
        cout << "Enter "<<endl;
        getline(cin,l);
        if(l == "-1"){
            break ;
        }
        else{
            f << l << endl ;
        }
    }
    f.close();
    ifstream i ;
    i.open("anushka.txt");
    string b ;
    while(i){
        getline(i,b);
        cout << b << endl ;
        

    }
    i.close();


}