#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream f ;
    f.open("a.txt");
    string line ;
    while(f){
        cout <<"Enter uh want to -1 to terminate " << endl ;
        getline(cin,line);
        if(line == "-1"){
            break;
        }
        else{
            f << line << endl ;
        }
    }
    f.close();
    ifstream f1 ;
    f1.open("a.txt");
    ofstream f2 ;
    f2.open("n.txt");
    string l ;
    while(! f1.eof()){
        getline(f1,l);
        f2<<l << endl ;
    }
    f1.close();
    f2.close();
    ifstream readf2 ;
    readf2.open("n.txt");
    string k ;
    while(!readf2.eof()){}



}
