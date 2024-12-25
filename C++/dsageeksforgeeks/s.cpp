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
    string s = "fgg";

}