#include "stackarray.cpp"
#include <iostream>
/*
Queue implementation using two stacks.
Queue class contains two stacks and a size.
isEmpty(): If both stacks are empty -> Queue is empty. Time Complexity: O(1)
isFull(): If total number of elements in both stacks is equal to queue size -> Queue is full. Time Complexity: O(1)
enqueue() : pushes the element into stack s1. Time Complexity : O(1)
dequeue() : all elements from stack s1 are popped into stack s2. Then an element is popped from stach s2 and returned.
Time Complexity: O(N) in worst case


*/
using namespace std;
template <class T>
class Queue{
    public:
        int size;
        Stack<T> s1, s2;
        bool isFull(){
            return size == (s1.Top + 1 + s2.Top + 1);
        }
        bool isEmpty(){
            return s1.isEmpty() && s2.isEmpty();
        }
        void enqueue(T x){
            if(isFull()){
                cout << "Queue is full " << endl;
                return;
            }
            s1.push(x);


        }
        T dequeue(){
            if(isEmpty()){
                throw ::std::underflow_error("Queue is empty");
            }
            if(s2.isEmpty()){
                while(!s1.isEmpty()){
                    s2.push(s1.pop());
                }
                
            }
            return s2.pop();
        }

};
int main(){
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(48);
    cout << q.dequeue() << " ";
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(48);
    q.enqueue(50);
    q.enqueue(60);
}