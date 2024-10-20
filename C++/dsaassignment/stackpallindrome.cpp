#include "stackarray.cpp"
#include <iostream>
/*
Checking Pallindrome using stack
We insert character by character into the stack.
After that we pop out those characters and necessarily append them to another string which now will be reverse of the original string.
Now if both original string and reversed string are equal. -> String is a pallindrome.
Otherwise Not.
Time Complexity: O(N);
Space Complexity: O(N);



*/
using namespace std;
bool checkPalindrome(string s){
    Stack<char> checker(s.size());
    for (int i = 0; i < s.size(); i++){
        checker.push(s[i]);
    }
    string ans;
    while(! checker.isEmpty()){
        ans += checker.pop();
    }
    return ans == s;
}
int main(){
    string s = "aabaa";
    if(checkPalindrome(s)){
        cout << "String is a pallindrome" << endl;
    }
    else{
        cout << "String is not a pallindrome " << endl;
    }
}