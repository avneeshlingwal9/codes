#include <iostream>
using namespace std ;
class Node{
public :
int data ; 
Node* previous ;
Node* next ; 
Node(int x){
    this->data = x ;
    this->previous = NULL ;
    this->next = NULL ;

}


};


class doublyLinkedList{
    public : 
    Node *head ; 
    doublyLinkedList(){
        this->head = NULL ;

    }
    void insertAtEnd(int x){
        Node* newnode = new Node(x);
        Node* temp = head ; 
        if(head == NULL){
            head = newnode ; 

        }
        else{
            while(temp->next != NULL){
                temp = temp->next ; 

            }
            temp->next = newnode ; 
            newnode->previous = temp ;

            
        } 






    }
    void sh(){
        Node* temp = head ; 
        while(temp!= NULL){
            cout << temp->data  << " "; 
            temp = temp->next; 

        }
        cout << endl ; 
    }
};
int main(){
    doublyLinkedList d ; 
    d.insertAtEnd(4);
    d.sh();
    d.insertAtEnd(5);
    d.sh();
    d.insertAtEnd(6);
    d.sh();
    
}