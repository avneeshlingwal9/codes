#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


string remov(string s){
    int len = s.length();
    string g = "";
    for(int i =0 ; i <len;i++){
        if((s[i] >=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            g+=s[i];
        }
    }
    return g ;
}
string convert(string s){
    int len = s.length();
    string g=s;
    for(int i =0 ; i < len ; i++){
        if(g[i]<=90){
            g[i]+=32;

        }
    }
    return g ; 
}



int checkPallindrome(string s){
    string f = remov(s);
    string g = convert(f);
    int l = g.length();
    int i = 0 , j = l-1;
    while(i<=j){
        if(g[i]!= g[j]){
            return 0;
        }
        else{
            i++;
            j--;
        }
    }
    return 1;
}
int main(){
    string k = " so";
    if(checkPallindrome(k)){
        cout << "It is pallindrome" << endl;
    }
    else{
        cout << "It is not pallindrome" << endl; 
    }
   


}