#include <iostream>
#include<fstream>
using namespace std ;
int  main(){
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
    ifstream file1 ;
    file1.open("anything.txt"); // Read mode 
    ofstream file2 ;
    file2.open("a.txt"); // New File 
    string lk ; 
    while(!file1.eof()){
        getline(file1,lk); // Copy 
        file2 << lk << endl ;
    }
    file1.close();
    file2.close();
    ifstream readfile2 ;
    readfile2.open("a.txt");
    string k ;
    while(!readfile2.eof()){
        getline(readfile2,k); // Display file2 
        cout << k << endl ;

    }

    


    }