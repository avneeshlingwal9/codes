#include <iostream>
#include <fstream>
using namespace std ;
int charcount(string filename){
    int count = 0 ;
    ifstream f ;
    f.open(filename);
    char c ;
    while(!f.eof()){
        f.get(c);
        count ++ ;
    }
    return count ;}
int wordcout(string filename){
    int count = 0 ;
    ifstream f ;
    f.open(filename);
    string word ;
    while(!f.eof()){
        f >> word ;
        count ++ ;
    }
    return count ;}
int linecount(string filename){
    int count = 0 ;
    ifstream f ;
    f.open(filename);
    string line ;
    while(!f.eof()){
        getline(f,line);
        count++ ;
    }
    return count ;}
int main(){
    ofstream fi ;
    string s = "anything.txt";
    fi.open(s);
    string line ;
    while(fi){
        cout << "Enter a string and enter -1 to terminate writing " << endl ;
        getline(cin,line);
        if(line == "-1"){
            break ;
        }
        else{
            fi << line << endl ; 
        }}
    fi.close();
    cout << "Character count is " << charcount(s) << endl ;
    cout << "Word count is " << wordcout(s) << endl ;
    cout << "Line count is " << linecount(s) << endl ;
}
