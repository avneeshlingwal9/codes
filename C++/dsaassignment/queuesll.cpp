#include "updatedsll.cpp"
#include <iostream>
using namespace std;
template <class T>
class Queue{
    public:
    LinkedList<T> l;

    bool isEmpty(){
        return l.head == NULL;
    }
    bool isFull(){
        return l.noSpace();
    }
    void enqueue(T x){

        l.insertAtFront(x);
    }
    T dequeue(){
        
        if(isEmpty()){
            throw::std::underflow_error("Queue is empty");
        }
        T ans = l.deleteAtBack();
        
        return ans;
    }
    T atFront(){
        if(isEmpty()){
            throw::std::underflow_error("Queue is empty");
        }
        return l.tail->data;
        }


    


};
/* int main(){
    try{
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
q.dequeue();


    }
    catch(underflow_error u){
        cout << endl << u.what() ;
    }
} */