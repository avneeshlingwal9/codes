#include "updatedsll.cpp"
#include <iostream>
/*
Priority Queue Implementation Using Linked List:
Largest element has the highest priority.
isEmpty(): Checks whether queue is empty or not. Time Complexity: O(1)
isFull(): Checks whether queue is full or not. Time Complexity: O(1)
enqueue(): Enqueues the element. By using sortInsertion in the linked list. Time Complexity : O(N)
dequeue() : Dequeues an element from the end of the linked list. Time Complexity : O(1)

*/
using namespace std;
template <class T>
class PriorityQueue{
    public:
        LinkedList<T> l;
        
        bool isEmpty(){
            return l.head == NULL;
        }
        bool isFull(){
            return l.noSpace();
        }
        void enqueue(T x){
            if(isFull()){
                cout << "Queue is Full " << endl;
            }
            l.sortedInsert(x);
        }
        T dequeue(){
            
            if(isEmpty()){
                throw ::std::underflow_error("Queue is empty");
            }
            T ans = l.deleteAtBack();
            return ans;
        }
};
/* int main(){
    try{
    PriorityQueue<int> q;
    q.enqueue(45);
    q.enqueue(5);
    q.enqueue(48);
    cout << q.dequeue();}
    catch(underflow_error u){
        cout << endl
             << u.what();
    }
} */
