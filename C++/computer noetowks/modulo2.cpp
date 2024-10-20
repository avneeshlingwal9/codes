#include <iostream>
using namespace std;
string exor(string a , string b){
    string res = "";
    for (int i = 0; i < a.length(); i++){
        if(a[i] == b[i] ){
            res.append("0");
        }
        else{
            res.append("1");
        }
        
    }
    return res;
    }

    void modulo2div(string todivide , string divisor){
        int dlen = divisor.length();
        int todivlen = todivide.length();
        string res = todivide;
        int i = 0;
        while(i <= todivlen - dlen){
            for (int j = 0; j < dlen; j++){
                res[i + j] = (res[i + j] == divisor[j]) ? '0' : '1';

            }
            while (i < todivlen && res[i] != '1'){
                i++;
            }
        }
        cout << res << endl; 
    }

int main(){
    string a = "100100000";
    string b = "1101";
    modulo2div(a, b);
}