#include <bits/stdc++.h>
using namespace std;


string conver(string s)
{ // Converting the string to one case either lower or else upper
    int len = s.length();
    string ans = s;
    for (int i = 0; i < len; i++)
    {
        if (ans[i] <= 90 && ans[i] >= 65)
        {
            ans[i] += 32;
        }
    }
    return ans;
    }
    string remov(string s){ //Removing spaces and special characters using ASCII 
        string ans="";
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            if((s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122) || (s[i] >=30 && s[i]<=39)){
                ans+=s[i];
            }
        }
        cout << "After removing " << ans << endl; 
        ans = conver(ans);
        return ans;
    }
    bool isPalindrome(string s) {
        string real = remov(s);
        cout << "Real " << real << endl;
        int len = real.length();
        int i = 0 , j = len-1;
        while(i<=j){
            if(real[i] != real[j]){
                return 0 ; 
            }
            else{
                i++;
                j--;
            }
        }
        return 1 ;
    }
int main(){
    string s = "0P";
    for (int i = 0; i < s.length();i++){
        int l = s[i];
        cout << l << " ";
    }
    
}
