#include "stackarray.cpp"
#include <iostream>
using namespace std;
/*
Sorting the stack using another stack:
So the algorithm is similar to insertion sort where we insert an element from the unsorted array to sorted array.
So similarly here we have our original stack and we are maintaining another auxillary stack in which we are inserting elements in descending order and if we found any element smaller than the top element then we insert it at the bottom and move all the elements back into the unsorted stack , hence forth maintaining the integrity of our descending order sorted stack(aux).
And when our initial stack becomes empty, we simply reverse the auxillary stack and in doing so we put the elements back in the original stack in sorted order.
So with this approach the :
Time Complexity is :O(N^2) + O(N) For worst and average case {O(N) for copying elements back}
For best case it is : O(N)
Space Complexity is : O(N)


*/
void stackSort(Stack<int>&s1 ){
    Stack<int> aux(s1.size);
    while(!s1.isEmpty()){
        int curr = s1.pop();
        while (!aux.isEmpty() && aux.atTop() > curr){
            s1.push(aux.pop());
        }
        aux.push(curr);

    }
    while(!aux.isEmpty()){
        s1.push(aux.pop());
    }
}
int main(){
    Stack<int> s1(10);
    s1.push(2);
    s1.push(4);
    s1.push(56);
    s1.push(45);
    s1.push(34);
    s1.push(95);
    s1.push(587);
    stackSort(s1);
    while(!s1.isEmpty()){
        cout << s1.pop() << " ";
    }
}