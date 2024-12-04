#include <bits/stdc++.h>
using namespace std;
bool checker(string str1 , string str2){
    int i = 0;
    for (auto c : str1)
    {
        if (i == str2.size())
        {
            return true;
        }
        if (i == str2.size() - 1 && c == str2[i])
        {
            return true;
        }
        if (c == str2[i])
        {
            i++;
        }
        }
        return false;
}
int main(){
    string str1 = "zc";
    string str2 = "ad";
    int i = 0; 
    for(auto &c : str1){
        if(i == str2.length()){
            break;
        }
        if(c == str2[i]){
            i++;
        }
        else if(c == 'z' && str2[i] == 'a'){
            c = 'a';
            i++;
        }
        else if(c+1 == str2[i]){
            c = c + 1;
            i++;
        }
    }
    cout << checker(str1, str2);
}