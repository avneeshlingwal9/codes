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
        for(int i = top ; i> -1 ; i--){
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
    int a =0 , b =0 ,  , carry = 0 , r = 0 ; 
    Stackk s1(10);
    Stackk s2(10);
    Stackk res(15);
    cout << "Enter the first number one by one -1 to terminate : - "<< endl ;
    while(a <10){
        int n ; 
        cin >> n;
        s1.push(n);
    }
    cout << "Enter the second number : - " << endl ;
    while(b!=-1){
        cin >> b ;
        s2.push(b);
    }
    while(!s1.isempty() && !s2.isempty()){
        r = s1.pop() + s2.pop() + carry ; 
        r = r%10 ;
        carry = carry/10;
        res.push(r);

    }
    while(!s1.isempty()){
        r = s1.pop() + carry ;
        r = r%10 ;
        carry = carry/10 ;
        res.push(r);

    }
    while(!s2.isempty()){
        r = s2.pop() + carry ;
        r = r%10 ;
        carry = carry/10 ;
        res.push(r);
    }
    res.push(carry);
    res.sh();
    



}