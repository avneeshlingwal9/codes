#include <iostream>
using namespace std ;
class Node{
    public :
    int data ;
    Node* next ;
    Node(int x){
        data = x ;
        next = NULL;
    }
};
class queueLinkedList{
    public :
    Node* front ;
    Node* rear ;
    queueLinkedList(){
        front = rear = NULL ;
    }
    void enqueue(int x){
        Node* newnode = new Node(x);
        if(this->isEmpty()){
            rear = newnode ;
            front = rear ;
        }
        else if(!newnode){
            cout << "Queue overflow." << endl ;

        }
        else {
            newnode->next = rear->next;
            rear->next = newnode;
            rear = newnode ;
        }
    }
    int dequeue(){
        if(this->isEmpty()){
            cout << "Queue is empty " << endl ; 
            return -1 ;}
        else if(front!=rear){
            int r = front->data ;
            Node* temp = front ;
            front = temp->next ;
            temp->next = NULL ;
            return r ;
            }
        else {
            int r = front->data ;
            front = rear = NULL ;
            return r ;

        }
        }
    
    bool isEmpty(){
        return front == NULL ;
    }
    int peek(){
        if(this->isEmpty()){
            cout << "Queue is empty" << endl ;
            return -1 ;
        }
        else{
            return front->data ;
        }
    }
    void display(){
        if(this->isEmpty()){
            cout << "Queue is empty" << endl ;
            return ; 
        }
        Node* temp = front ;
        cout << "Elements of the queue are : " << endl ;
        while(temp!=NULL){
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl ;
    }
    
    
    
    };
int main(){
    int  con = 0  ;
    
    queueLinkedList q1;
    cout << "Enter 1 for enqueue." << "\nEnter 2 for dequeue. " <<"\nEnter 3 for peek." <<"\nEnter 4 for display." <<"\nEnter 5 for isEmpty."<< endl ;
    cout << "\nEnter -1 to exit." << endl ;
    while(con!=-1){
        cout << "Enter a choice:" << endl ;
        cin >> con ; 
        switch (con)
        {
        case 1:
        int l ;
        cout << "Enter the element: " << endl ;
        cin >> l ; 
        q1.enqueue(l);
            break;
        case 2 :
        
        cout << "Popped element is " << q1.dequeue() << endl ; 
            break ;
        case 3 :
        cout <<"Element at the top is "<<  q1.peek() << endl ;
        break ;
        case 4:
        
        q1.display();
        break;
        case 5:
        if(q1.isEmpty()){
            cout << "Queue is empty." << endl ;
            break;
        }
        cout << "Queue is not empty." << endl; 
        break;

        
        default :
        con = -1 ;
        break ;}
            

    }
        

 }       