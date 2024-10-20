#include <iostream>
using namespace std ;
class Node{
    public :
    int data ;
    Node* next ;
    Node(int x){
        this->data = x ;
        this->next = NULL ;
    }
};
class orderedSinglyLinkedList{
    public :
    Node* head ;
    orderedSinglyLinkedList(){
        this->head = NULL ;
    }
    void insertord(int x){
        Node* newnode = new Node(x);
        if(head == NULL || x <= head->data ){
            newnode->next = head ;
            head = newnode ;
        }
        else{
            Node* temp = head ;
            while(temp->next!=NULL && temp->next->data < x){
                temp = temp->next ;

            }
            newnode->next = temp->next ;
            temp->next = newnode ;



        }

    }
    void insertend(int x){
        Node* newnode = new Node(x);
        if(head == NULL){
            head = newnode ;
        }
        else{
            Node* temp = head ;
            while(temp->next != NULL){
                temp = temp->next ;
            }
            newnode->next = temp->next ;
            temp->next = newnode ;


        }
    }
    void sh(){
        Node* temp = head ;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next ;
        }
        cout << endl ;
    }
};
void mergelist(Node* head1 , Node* head2){
    orderedSinglyLinkedList k ;
    Node* temp1 = head1 ;
    Node* temp2 = head2 ; 
    while(temp1!=NULL && temp2!= NULL){
        if(temp1->data < temp2->data){
            k.insertend(temp1->data);
            temp1 = temp1->next ;
                    
        }
        else{
            k.insertend(temp2->data);
            temp2 = temp2->next ;
        }

    }
    while(temp1!=NULL){
        k.insertord(temp1->data);
        temp1 = temp1->next ;
    }
    while(temp2!= NULL){
        k.insertord(temp2->data);
        temp2 = temp2->next ;
    }
    k.sh();
}
int main(){
    orderedSinglyLinkedList o ;
    o.insertord(4);
    o.sh();
    o.insertord(6);
    o.sh();
    o.insertord(5);
    o.sh();
    o.insertord(4);
    o.sh();
    o.insertord(3);
    o.sh();
    o.insertord(40);
    o.sh();
    o.insertord(30);
    orderedSinglyLinkedList s ;
    s.insertord(45);
    s.insertord(7);
    s.insertord(9);
    s.sh();
    mergelist( s.head , o.head);



}
