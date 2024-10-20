#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream percen;

    percen.open("st.txt");
    string line;
    int flag = 1;
    while(percen){
        getline(cin, line);
        if(line == "-1"){
            break;
        }
        percen << line << endl;


    }


    

    percen.close();

}
