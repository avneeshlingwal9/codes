#include <iostream>
using namespace std ;

class stackArray{

    public :
    int size ;

    char* arr ;
    int top ; 
    stackArray(int size){
        this->size = size ;
        arr = new char[size];
        top =-1 ; 

    
    }
    void push(char x){
        if(!this->isFull()){
        arr[++top] = x ;
        }
        else{
            cout << "Stack Overflow " << endl ;

        }
    }
    char pop(){
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
    char peek(){
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
int orderofprecedence(char a){
    switch (a){
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2 ;
        case '^':
        return 3;

    }


}
bool isoperator(char a){
    if(a>'0' && a <'9'){
        return false ;
    }
    return true ;
}
string infixtopostfix(string q , string ans){
    stackArray m(50);
    for(int i =0 ;i < q.length(); i++){
        if(isoperator(q[i])){
            if(m.)
        }

    }

}
int main(){
















}