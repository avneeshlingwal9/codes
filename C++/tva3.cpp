#include <iostream>
using namespace std ; 
class Stackk{
    public :
    int size ; 
    int* arr ; 
    int top ; 
    Stackk(int x){
        this->size = x ;
        this->top = -1 ;
        this->arr = new int[size];
    }
    void push(int e){
        if(top == size-1){
            cout << "Stack overflow " << endl ;
            
        }
        else{
         
            arr[++top] = e ;
        }



        
    }
    int pop(){
        if(top == -1){
            cout << "Stack underflow "<< endl ;
            return -1 ; 

        }
        else{
            return arr[top--];
        }

    }
    void sh(){
        cout << "top " << top  << endl; 
        for(int i = 0 ; i < top+1 ; i++){
            cout << arr[i] << " " ;
        }
    cout << endl ;
    }
    bool isempty(){
        if(top == -1){
            return true ;
        }
        return false ;
    }
    bool isfull(){
        if(top == size - 1){
            return true ;
        }
        return false ;
    }
    int peek(){
        if(this->isempty()){
            cout << "Stack is empty"  ;
            return -1 ; 
        }
        else{
            return arr[top];
        }
    }










};
int main(){
Stackk k(6);
k.push(4);
k.sh();
k.push(5);
k.sh();
k.push(6);
k.sh();
k.push(7);
k.sh();
k.push(8);
k.sh();
k.push(9);
k.sh();
k.pop();
k.sh();
k.pop();
k.sh();
cout << k.peek() << endl;


}