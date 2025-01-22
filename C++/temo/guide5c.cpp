#include <iostream>
using namespace std ;


class stackArray{


    public :
    int size ;

    int* arr ;
    int top ; 
    stackArray(int size){
        this->size = size ;
        arr = new int[size];
        top =-1 ; 

    
    }
    void push(int x){
        if(!this->isFull()){
        arr[++top] = x ;
        }
        else{
            cout << "Stack Overflow " << endl ;

        }
    }
    int pop(){
        if(!this->isEmpty()){
            return arr[top--];
        }
        cout << "Stack underflow " << endl ;
        return -1 ;
    }
    bool isFull(){
        return top == size-1 ;
    }
    bool isEmpty(){
        return top == -1 ;
    }
    int peek(){
        if(!this->isEmpty()){
            return arr[top];

        }
        cout << "Stack underflow " << endl ;
        return -1 ;
    }
    void show(){
        if(this->isEmpty()){
            cout << "Stack is empty." << endl ;
            return ;
        }
        cout << "Elements of the stack are: " << endl ;

        for(int i = 0 ; i <= top ; i++){
            cout << arr[i] << " " ;
        }
        cout << endl ; 
    }


};
int calc(int op1 , int op2 , char op ){
    switch(op){
        case '+':
        return op1+op2;
        case '-':
        return op1-op2;
        case '*':
        return op1*op2;
        case '/':
        return op2/op1;
        case '^':
        return op1^op2;
        default:
        return -1 ;
    }

};

int evaluation(string s){
    stackArray sol(50);
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] > '0' && s[i] < '9'){
            int o = (int) ( s[i]- '0');
            sol.push(o);
        }
        else{
            int op1 = sol.pop();
            int op2 = sol.pop();
            int ans = calc(op1,op2,s[i]);
            sol.push(ans);
        }

    }
    return sol.pop();
}
int main(){
    string s ;
    cout << "Enter a postfix expression: " << endl ;
    getline(cin,s);
    cout << evaluation(s);


}