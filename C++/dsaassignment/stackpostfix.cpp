#include "stackarray.cpp"
#include <math.h>
#include <iostream>
/*
Using stack to do the postfix evaluation of the expression.
isNum: returns true if it is a digit.
conversion: Converts character to integer.
calculate: Calculates the expression based on the value and symbol.
isOperand: Checks whether a valid operand or not.
postfix: Evaluates the postfix expression using a stack.
Time Complexity : O(N)
Space Complexity : O(N)














*/
using namespace std;
bool isNum(char a){
    return a - '0' >= 0 && a - '0' <= 9;
}
int conversion(char a){
    return a - '0';
}
int calculate(int x1 , int x2 , char symbol){
    switch (symbol){
        case '+':
            return x1 + x2;

        case '-':
            return x1 - x2;
        case '*':
            return x1 * x2;
        case '/':
            if(x2 == 0){
                cout << "Divison by zero not allowed " << endl;
                return -1;
            }
            return x1 / x2;
        case '^':
            return pow(x1, x2);

        default:

        cout << "Not supported " << endl;
            return -1;
    }


}
bool isOperand(char a){
    return a == '+' || a == '-' || a == '/' || a == '*' || a == '^';
}

int postfix(string s){
    Stack<int> toStore(s.size());
    for (int i = 0; i < s.size(); i++){
        if(isNum(s[i])){
            int c = conversion(s[i]);
            toStore.push(c);
        }
        else if(isOperand(s[i])){
            int x2 = toStore.pop();
            int x1 = toStore.pop();
            int res = calculate(x1,x2,s[i]);
            toStore.push(res);
        }

    }
    return toStore.pop();
}
int main(){

    
    
    string exp = "231*+9-";
    cout << postfix(exp);

}