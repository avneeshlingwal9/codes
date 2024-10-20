#include "array.cpp"
#include <iostream>
/*
Implementation of the priority queues using arrays.
Contains a class Priority Queue with functions: 
Priority such that lower value has higher priority
isFull() : Checks whether queue is full or not. O(1)
isEmpty(): Checks whether queue is empty or not. O(1)
enqueue(): Uses a function to find right pos of element and then using shifting insert it in array. 
Time Complexity: O(2N) for shifting of elements and finding right position.
dequeue(): Removes an element. 
Time Complexity : O(1)



*/
using namespace std;
template <class T>
class PriorityQueue{
    public:

    int size;
    T *A;
    int front;
    int rear;
    PriorityQueue(){
        size = 10;
        A = new T[size];
        front = rear = 0;
    }
    PriorityQueue(int x){
        size = x;
        A = new T[size];
        front = rear = 0;
    }
    
    bool isFull(){
        return rear == size;
    }
    bool isEmpty(){
        return front == rear;
    }
    void enqueue(T x){
        if(isFull()){
            cout << "Queue is full " << endl;
            return;
        }

        int pos = findRightPosition(A, front, rear, x);
        shifting(A, pos, size, x);
        rear++;
    }
    T dequeue(){
        if(isEmpty()){
            throw ::std::underflow_error("Queue is empty");
        }
        T ans = A[front];
        front++;
        return ans;
    }



};
int main(){
    try{
    PriorityQueue<int> p(5);
    p.enqueue(45);
    p.enqueue(34);
    p.enqueue(45);
    p.enqueue(23);
    cout << p.dequeue();}
    catch(underflow_error u){
        cout << "/n" << u.what();
    }
}