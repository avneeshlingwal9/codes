#include <iostream>
using namespace std;
/*
Circular queue implementation using arrays.
Declared a class Queue with two constructors:
1-> Default one : Queue() - front = rear = 0 , size = 10 and array of size 10.
2-> Paramaterized one : Queue(int s) : front = rear = 0 , size = s and array of size s.
In circular queue of size (s) , only s-1 elements can be inserted as one block of space 
is used to differentiate between empty and full queue.
isFull() : Checks whether queue is full or not. Time Complexity: O(1)
isEmpty() : Checks whether queue is empty or not. Time Complexity : O(1)
enqueue(T x): Enqueues an element in the circular queue. Time Complexity: O(1)
T dequeue(): Dequeues an element. Time Complexity : O(1)
*/
template <class T>
class CircularQueue{

public:
    int front;
    int rear;
    int size;
    T *A;
    CircularQueue(){
        front = rear = 0;
        size = 10;
        A = new T[size];
    }
    CircularQueue(int s){
        front = rear = 0;
        size = s;
        A = new T[size];
    }
    bool isFull(){
        return (rear + 1) % size == front;
    }
    bool isEmpty(){
        return front == rear;
    }
    void enqueue(T x){
        if(isFull()){
            cout << "Queue is full " << endl;
            return;
        }
        A[rear] = x;
        rear = (rear + 1) % size;
    }
    T dequeue(){
        if(isEmpty()){
            throw ::std::underflow_error("Queue is empty");
        }
        T ans = A[front];
        front = (front + 1) % size;
        return ans;
    }

};
int main(){
    try{
    CircularQueue<int> q(4);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    q.enqueue(7);
    q.enqueue(8);
        }
    catch(underflow_error u){
        cout << endl
             << u.what();
    }

}