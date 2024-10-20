#include <iostream>
using namespace std;
class CRC{
    public : 
    string sdata,divisor,rdata,rem;
    int dtlen, cdlen,divlen;
    void sender(){
        cout << "Please enter the data: " << endl;
        getline(cin,sdata);
        cout << "sdata " << sdata << endl; 
        cout << "Please enter the divisor: " << endl;
        getline(cin,divisor);
        divlen = divisor.length();
        dtlen = sdata.length();
        encoder();
        modulodiv(sdata,divisor);
        
        cout << "Sent codeword is: " << sdata << endl; 
        cout << "Divisor is: " << divisor << endl; 
        

        }
        


    
    void encoder(){
        for(int i = 0 ; i < divlen-1; i++){
            sdata+="0";

        }
        cdlen = sdata.length();
         
    }
    string exor(string a , string b){
    string res = "";
    for (int i = a.length() - 1; i > -1; i--)
    {
        if(a[i]==b[i]){
            res+="0";
        }
        else{
            res+="1";
        }
    }
    return res;

}
void modulodiv(string a , string b){
    int j = b.length();
    int l = a.length();
    string div = a.substr(0,j);
    
    while(j <= l){
        
        if(div.length()==b.length()){
            div = exor(div,b);
            rem = div ;
            int n = div.find("1");
            if(n == string::npos){
                break;
            }
            div = div.substr(n);
        }
        else{
            div+=a[j++];
            rem = div ;
            

        }

    }
    sdata.replace(cdlen-rem.length(),cdlen,rem.substr(1,j));


}
void receiver(){
    cout << "Enter the received data: " << endl ;
    getline(cin,rdata);
    modulodiv(rdata,divisor);
    if(rem.find("1")==string::npos){
        cout << "Data transmitte " << endl;
    }
    else {
        cout << "Data corrupted" << endl;
    }
}





};


int main(){
    CRC c ;
    c.sender();
    c.receiver();
}