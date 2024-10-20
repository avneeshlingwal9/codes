#include <iostream>
using namespace std ; 
class Node{
    public :
    int data ; 
    Node* next ; 
    Node(int x){
        this->data = x ; 
        this->next = NULL;
    }
};
class queuee{
    public : 
    Node* head = NULL ;
    Node* rear= NULL ;
    void inser(int x){
        Node* newnode = new Node(x);
        if(newnode == NULL){
            cout << "Overflow\n";
        }
        else{
            if(head == NULL){
                head = newnode;
                rear = newnode;
            }
            else{
                rear->next = newnode ;
                rear = newnode ;
                
            }
        }
    }
    int deque(){
        if(head == NULL){
            cout << "Underflow\n" ;
            return -1 ;
        }
        else{
            Node* temp = head ;
            head = temp->next ;
            temp->next = NULL ;
            return temp->data; 
        }
    }
    void sh(){
        Node* temp = head ;
        while(temp!= NULL){
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << endl ;
    }





};
int main(){
    queuee q ; 
    q.inser(4);
    q.sh();
    q.inser(5);
    q.sh();
    q.inser(8);
    q.sh();
    q.deque();
    q.sh();
}