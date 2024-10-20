#include <iostream>
#include "queuesll.cpp"
/*
Implementation of stack using queue.
Operations:
isEmpty() : Time Complexity: O(1)
isFull(): Time Complexity : O(1)
push() : Time Complexity : O(N)
pop() : Time Complexity : O(1)

*/
using namespace std;
template <class T>
class Stack{
    public:
        Queue<T> q1;
        
        bool isEmpty(){
            return q1.isEmpty();
        }
        bool isFull(){
            return q1.isFull();
        }
        void push(T x)
        {
            if(isFull()){
                cout << "Queue is full " << endl;
                return;
            }
            q1.enqueue(x);
            while(q1.atFront() != x){
                T aux = q1.dequeue();
                q1.enqueue(aux);
            }

        }
        T pop(){
        
        if(isEmpty()){
            throw::std::underflow_error("Queue is empty");
        }
        T ans = q1.dequeue();
        
        return ans;
    }
};
int main(){

    Stack<int> s;
    s.push(6);
    s.push(5);
    s.push(8);
    s.push(9);
    cout << s.pop();
}