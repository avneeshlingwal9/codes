#include "stackarray.cpp"
#include <iostream>
/*
So using three boolean functions:
isOpening : To check if an valid opening parenthesis or not.
isEnding : To check if an valid closing parenthesis or not.
checkPair: To check whether two characters are right pair or not.
parenthesesChecker: Checking whether a string has valid parenthesis or not.
Utilizes a stack to check valid parenthesis.
If opening bracket : Pushes into the stack.
If matching closing : Pops out from the stack.
In any other case simply returns false;
Time Complexity: O(N)
Space Complexity: O(N)


*/
using namespace std;
bool isOpening(char a){
    return a == '(' || a == '[' || a == '{';
}
bool isEnding(char a){
    return a == '}' || a == ')' || a == ']';
}
bool checkPair(char a , char b){
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

bool parenthesesChecker(string s){
    Stack<char> checker(s.length());
    for (int i = 0; i < s.length(); i++){
        if(isOpening(s[i])){
            checker.push(s[i]);
        }
        else if(isEnding(s[i]) ){
            if(checker.isEmpty() && !checkPair(s[i], checker.atTop()))
            {
                return false;
            }
            checker.pop();
        }
    }
    return checker.isEmpty();
}

int main(){
    string s = "(a + b) * (c - d)";
    if(parenthesesChecker(s)){
        cout << "Parenthesis Matched " << endl;
    }
    else{
        cout << "Parenthesis not matched " << endl;
    }

}
