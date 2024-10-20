#include <iostream>
#include <string>

using namespace std;
  string exor(string a, string b)
    {
        string ans;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i])
            {
                ans.append("0");
            }
            else{
            ans.append("1");
        }


    }
    return ans; 
}
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
}
  
void addzeros(){
    for (int i = 1; i < dlen; i++){
        codeword.append("0");
        
    }
    
}
void modulo2div(){
    
    dataword = codeword;
    

    int i = 0; 
    res = (dataword).substr(i,dlen);
    int coun = dlen;
    do{
        
        res = exor(res, divisor);
    
        i = res.find_first_of('1');
        
            res = res.substr(i);
        
        
        
        
        
        
        
        res.append((dataword).substr(coun, i));
        coun += i; 

    } while (coun <= dataword.length()-1);
    res = exor(res, divisor);
    i = res.find('1');
    
    res = res.substr(i);
    dataword.replace(dataword.length()-res.length(),res.length() , res);
}
void send(){
    addzeros();
    modulo2div();
    cout << "Dataword sent is " << dataword << endl; 
}
void receive(){
    cout << "Enter the received data " << endl;
    getline(cin, rdata);
     int i = 0; 
    res = (rdata).substr(i,dlen);
    int coun = dlen;
    do{
        
        res = exor(res, divisor);

        i = res.find_first_of('1');
        if(i == string::npos){
            break;
        }

        res = res.substr(i);
        
        
        
        res.append((rdata).substr(coun, i));
        coun += i; 

    } while (coun <= rdata.length()-1);
    cout << "res before " << res <<  endl; 
    res = exor(res, divisor);
    cout << res << endl;
    string ch;
    for (int i = 0; i < dlen; i++){
        ch.append("0");
    }
    if(res == ch){
        cout << "Data transmission successful " << endl;
    }
    else {
        cout << "Not successful " << endl; 
    }
}

};
string generate(int n ){
    string r = "";
    for (int i = 0; i < n; i++){
        r.append("0");
    }
    return r; 
}
string modul(string dividend , string divisor){
    int divlen = dividend.length();
    int divislen = divisor.length();
    string rem = dividend.substr(0, divislen);
    cout << "rem before " << rem << endl; 
    int p = divislen;
    string r = generate(p);
    while(p < divlen){
        if(rem[0] == '1'){
            rem = exor(rem, divisor) + dividend[p];
            cout << "rem " << rem << endl; 
        }
        else {
            for (int i = 0; i < p-1; i++){
                rem[i] = rem[i+1] ;
            }
            cout << "rem before pulling " << rem << endl; 
            rem[p - 1] = dividend[p] ;
            cout << "rem in loop " << rem << endl; 
        }
        p++;
        cout << "p" << p << endl; 
    }
    if(rem[0]=='1'){
        rem = exor(rem, divisor);
        
    }
    
    return rem;
}
int main(){
    string a = "10110100000";
    string b = "10011";
    cout << modul(a, b);
}