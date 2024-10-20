#include <iostream>
using namespace std ;
class Node{
    public :
    int data ;
    Node* next ;
    Node* prev ;
    Node(int x){
        this->data = x ;
        this->next = NULL ;
        this->prev = NULL ;

    }
};
class dblylinkedlist{
    public :
    Node* head ;
    dblylinkedlist(){
        this->head = NULL ;
    }
    void insertatend(int x){
        Node* newnode = new Node(x);
        if(head== NULL){
            head = newnode ;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next ;

            }
            newnode->next = temp->next ;
            temp->next = newnode ;
            newnode->prev = temp ;

        }

    }
    void sh(){
        Node* temp = head ;
        while(temp!=NULL){
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        cout << endl ; 
    }
};
int main(){
    dblylinkedlist d ;
    d.insertatend(4);
    d.sh();
    d.insertatend(5);
    d.sh();
    d.insertatend(6);
    d.sh();
}