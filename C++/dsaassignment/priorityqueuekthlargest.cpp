#include <iostream>
#include "priorityqueueslinkedlist.cpp"
/*
Finding kth largest element in the priority queue using recursion.
Recursively dequeing elements, till k == 1 or kth largest element is reached.
Then adding back the dequeued elements.
Time Complexity: O(K)
Space Complexity: O(K) 
where K is kth largest element.
*/
using namespace std;
template <class T>
T kthLargest(PriorityQueue<T> &p , int k){
    if(k == 1){
        return p.atFront();
    }
    T curr = p.dequeue();
    T ans = kthLargest(p, k - 1);
    p.enqueue(curr);
    return ans;
}
int main()

{
    /* PriorityQueue<int> p;
    p.enqueue(45);
    p.enqueue(48);
    p.enqueue(5);
    p.enqueue(43);
    p.enqueue(34);
    p.enqueue(9);
    cout << kthLargest(p,2); */
    cout << 45;
}
