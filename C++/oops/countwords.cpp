#include <iostream>
#include <fstream>
using namespace std;
int countWords(ifstream &coun){
    string line;
    int count = 0;
    while(getline(coun,line)){
        int len = line.length();
        for (int i = 0; i < len; i++){
            if((line[i] >='a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') ){
                count++;
            }
        }
    }
    return count;
}
int main(){
    ifstream count;
    count.open("st.txt");
    cout << countWords(count);
    count.close();
}
