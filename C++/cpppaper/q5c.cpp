#include <iostream> 
#include <fstream>
using namespace std;
int wordcout(string filename){ // Wordcount function practical wala 
    int count = 0 ;
    ifstream f(filename);
    string word ;
    while(f >> word){ // if f>> word condition is true works same as eof condition 
        count ++ ;
    }
    f.close();
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
    int l = wordcout(s);
    cout << l ;
    ofstream wr ; // Opening new file and writing word count into it .
    wr.open("newcopy.txt");
    wr << "Number of words in the file are " << l << endl; 
    wr.close();


}