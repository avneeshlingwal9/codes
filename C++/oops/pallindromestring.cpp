#include <iostream>
using namespace std;
void checkPallindrome(string s , int i , int j ){
    if(i >= j){
        cout << "String is pallindrome " << endl;
        return;
    }

    if(s[i]  != s[j]){
        cout << "String is not pallindrome " << endl;
        return;
    }

    checkPallindrome(s, i + 1, j - 1);
}
int main(){
    string s = "aaba";
    checkPallindrome(s, 0, s.length() - 1);
}