#include <iostream>
#include "queuesll.cpp"

/*
Reversal of queue using  recursion.
We are going to exploit the fact that recursion uses stack. So we are going to dequeue elements till queue is empty and then enqueue them back, in process necessarily reversing the queue.
Time Complexity : O(N)
Space Complexity: O(N)
where N is the number of elements in the queue.

*/
using namespace std;
template <class T>
void reverseQ(Queue<T> &q){
    if(q.isEmpty()){
        return;
    }
    T curr = q.dequeue();
    reverseQ(q);
    q.enqueue(curr);
}
int main(){
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    reverseQ(q);
    while(!q.isEmpty()){
        cout << q.dequeue() << " ";
    }
    
}