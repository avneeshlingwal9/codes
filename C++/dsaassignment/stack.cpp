#include "sll.cpp"
/*
Importing the singly linked list.
Implementation of the Stack using singly linked list.
Time Complexity of Various Operations:
push() : O(1)
pop()  : O(1)
isFull() : O(1) using check function for checking whether there is some storage left or not.
isEmpty() : O(1) To check whether Stack is Empty or not.




*/
using namespace std;
template <class T>
class Stack{
    public:
    int Top;
    LinkedList<T> values;
    Stack(){
        Top = -1;
    }
    void push(int data){
        values.insertAtFront(data);
        Top++;
    }
    int pop(){
        if(Top == -1){
            throw ::std::underflow_error("Underflow error");
        }
        int data = values.deleteAtFront();
        Top--;
        return data;
    }
    int isFull(){
        return values.check();
    }
    int isEmpty(){
        if(Top == -1){
            return 1 ;
        }
        return 0 ;
    }

};
int main(){
    try{
    Stack <int>s  ; 
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    cout << s.pop() << endl;
    cout << s.pop() << " ";}
    catch(underflow_error &u){
        cout << "\n"
             << u.what();
    }
    

}