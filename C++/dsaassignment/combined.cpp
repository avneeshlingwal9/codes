#include <iostream>
using namespace std;


/*
Priority Queue Implementation Using Linked List:
Largest element has the highest priority.
isEmpty(): Checks whether queue is empty or not. Time Complexity: O(1)
isFull(): Checks whether queue is full or not. Time Complexity: O(1)
enqueue(): Enqueues the element. By using sortInsertion in the linked list. Time Complexity : O(N)
dequeue() : Dequeues an element from the end of the linked list. Time Complexity : O(1)

*/
template <class T> 
class Node{
    public:
    T data;
    Node* next;
    Node(){
        next = NULL;
    }
    Node(T x){
        data = x ;
    }
};
template <class T>
class LinkedList{
    public:
    Node <T>* head ; 
    Node <T>* tail;
    LinkedList(){
        head = NULL;
        tail=NULL;
    }
    void insertAtFront(T data){
        Node <T> *ne = new Node<T>(data);
        ne->next= head;
        if(head == NULL){
            tail = ne;
        } 

        head = ne ;}

    void insertAtBack(T data){
        Node<T> *ne = new Node<T>(data);
        if(head == NULL){
            head = ne ;
            tail = ne;
            
        }
        else{
            tail->next= ne;
            tail = ne;
        }

    }
    void insertAtAnyPosition(T data , int pos){
        Node<T> * ne = new Node<T>(data);
        
        if(head == NULL){
            head = ne;
            tail = ne;
            return;
        }
   
        if(pos == 1){
            head->next = ne;
            head = ne;
            return;
        }
        Node<T> *temp = head;
        for (int i = 1; i < pos - 1 && temp ; i++){
            temp = temp->next;

        }
        
        ne->next = temp->next;
        temp->next = ne;
        if(ne->next == NULL){
            tail = ne;
        }
                
    }
/*     int findPos(T dat){
        int pos = 1;
        Node<T> *temp = head;
        while(temp->next!= NULL && temp->data <= dat){
            temp = temp->next;
            pos++;
        }
        return pos;
    } */

/*
Inserts the element in the sorted order in the linked list.
Time Complexity: O(N)
*/
    void sortedInsert(T data){
        Node<T> *p = head, *q = NULL;

        Node<T> *newN = new Node<T>(data);
        if(head == NULL){
            head = newN;
            tail = newN;
            return;
        }
        if(data < head->data){
            newN->next = head;
            head = newN;
            return;
        }
        while( p  && p->data < newN->data){
            q = p;
            p = p->next;

        }
        newN->next = q->next;
        q->next = newN;
        if(newN->next == NULL){
            tail = newN;
        }
        }
    T deleteAtFront(){
        if(head == NULL){
            throw::std::underflow_error("Linked list is empty");
        }
        Node<T>* temp = head;
        
        head = head->next;
        int d = temp->data;
        if(head == NULL){
            tail = NULL;
        }
        delete temp ; 
        return d;
    }
    T deleteAtBack(){
        if(head == NULL){
            throw::std::underflow_error("Linked list is empty");}
        else if(head == tail){
            Node<T>* temp = head;
            T d = temp->data;
            head = NULL;
            tail = NULL;
            delete temp;

            return d;
        }
            Node<T>* temp = head;
            while(temp->next != tail){
                temp = temp->next;

            }
            T d = tail->data;
            tail = temp;
            temp = tail->next;
            delete temp;
            return d;
        
   
    }
    T deleteAtAnyPosition(int pos){
        Node<T>* curr = head;
        Node<T>* prev = NULL;
        for(int i = 0 ; i < pos-1 && curr;i++){
            prev = curr;
            curr = curr->next;
        }
        if(curr == head){
            head = NULL;
        }
        else{
            prev->next = curr->next;
            curr->next= NULL;    
        }
        delete curr ;

    }
    int noSpace(){
        Node<T>* ne = new Node<T>;
        if(ne == NULL){
            return 1 ; 
        }
        else{
            return 0 ; 
        }
    }

};

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
        T atFront(){
            if(isEmpty()){
                throw ::std::underflow_error("Queue is empty");
            }
            return l.tail->data;
            
            
        }
};



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
int main(){
    PriorityQueue<int> p;
    p.enqueue(45);
    p.enqueue(48);
    p.enqueue(5);
    p.enqueue(43);
    p.enqueue(34);
    p.enqueue(9);
    cout << kthLargest(p,2);

}