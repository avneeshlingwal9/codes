#include <iostream>
using namespace std;
template <class T>
class Stack{
    public:
        int size;
        T *A;
        int Top = -1;
        Stack(){
            size = 10;
            A = new T[size];
        }
        Stack(int n)
        {
            size = n;
            A = new T[size];
    }
    ~Stack(){
        delete []A;
    }
    bool isEmpty(){
        return Top == -1;
    }
    bool isFull(){
        return Top == size-1;
    }
    void push(T x){
        if( isFull()){
            throw ::std::overflow_error("Stack overflow");
        }
        Top++;
        A[Top] = x;
    }
    T pop(){
        
        if(isEmpty()){
            throw ::std::underflow_error("Stack underflow");
        }
        T ans = A[Top];
        Top--;
        return ans;

    }
    T atTop(){
        if(isEmpty()){
            throw ::std::underflow_error("Stack underflow");
        }
        return A[Top];
    }


};
int main(){
    try{
    Stack <string> s(5);
    s.push("a");
    s.push("b");
    s.push("c");
    s.push("d");
    s.push("e");
    s.push("f");
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    s.pop();
    }
    
    catch (underflow_error& u){
        cout << "\n"
             << u.what();
    } 
    catch(overflow_error& o){
        cout << "\n"
             << o.what();
    }

}