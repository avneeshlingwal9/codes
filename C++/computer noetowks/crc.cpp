#include <iostream>
using namespace std;
class CRC{
    public : 
    string sdata,divisor,rdata,rem;
    int dtlen, cdlen,divlen;
    CRC(){
        cout << "Please enter the data: " << endl;
        getline(cin,sdata);
        cout << "Please enter the divisor: " << endl;
        getline(cin,divisor);
        divlen = divisor.length();
        dtlen = sdata.length();
        


    }
    void encoder(){
        for(int i = 0 ; i < divlen-1; i++){
            sdata+="0";

        }
        cdlen = sdata.length();
        
    }
    string exor(string a , string b){
    string res = "";
    for(int i = 0 ; i < a.length(); i++){
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
    rem=div;
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
    sdata.replace(cdlen-rem.length(),cdlen,rem);


}
void display(){
    cout <<"Entered dataword is " << sdata << endl;
    cout << "Entered divisor is " << divisor << endl;
    cout << "Codeword obtained is: " <<  sdata << endl ;
}





};


int main(){
    CRC c ;
    c.display();
    c.encoder();
c.modulodiv(c.sdata,c.divisor);
    c.display();
}