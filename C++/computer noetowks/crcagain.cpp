#include <iostream>

using namespace std;

class CRC{
    public :
    string codeword;
    string dataword;
    string divisor;
    string rdata;
    string res;
    int dlen; 
CRC(){
    cout << "Enter the data to be sent : " << endl;
    getline(cin, codeword);
    cout << "Enter the divisor : " << endl;
    getline(cin, divisor);
    dlen = divisor.length();
    dataword = codeword;
}
  
void addzeros(){
    for (int i = 1; i < dlen; i++){
        codeword.append("0");
        
    }
    
}
void modulo2div(string todivide ){
         
        int todivlen = todivide.length();
        res = todivide;
        int i = 0;
        while(i <= todivlen - dlen){
            for (int j = 0; j < dlen; j++){
                res[i + j] = (res[i + j] == divisor[j]) ? '0' : '1';

            }
            while (i < todivlen && res[i] != '1'){
                i++;
            }
        }
        res = res.substr(todivlen - dlen+1);
        dataword.append(res);
    }
void send(){
    addzeros();
    modulo2div(codeword);
    cout << "Dataword sent is " << dataword << endl; 
}
void receive(){
    cout << "Enter the received data " << endl;
    getline(cin, rdata);
    modulo2div(rdata);
    if(res.find('1') == string::npos){
        cout << "Data transmitted successfully " << endl; 
    }
    else {
        cout << "Data transmission failed " << endl; 
    }
}

};
int main(){
    CRC c;
    c.send();
    c.receive();
    

}