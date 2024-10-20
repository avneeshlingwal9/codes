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
class linkedList{
    public :
    Node* head ;
    linkedList(){
        this->head = NULL;
    }
    void insertatbegin(int x){
        Node* newnode = new Node(x);
        if(head== NULL){
            head = newnode ;
        }
        else{
            newnode->next = head ;
            head = newnode ;
        }
    }
    void recursionreverse(Node* temp){

        if(temp->next->next==NULL){
            head = temp->next ;
            head->next = temp ;

            return ;
        }
        else{
            recursionreverse(temp->next);
            temp->next->next = temp ; 
            temp->next = NULL ;
            

            
        }
    }
    void reverseiteration(){
        Node* temp = head ;
        Node* nex = NULL ;
        Node* prev = NULL ;
        while(temp!= NULL){
            nex = temp->next ;
            temp->next = prev ;
            prev = temp ;
            temp = nex ;

    
        }
        head = prev ; 
    }
    void sh(){
        Node* temp =  head ; 
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next ;
        }
        cout << endl ;

    }


};
int main(){
    linkedList l ;
    l.insertatbegin(4);
    l.sh();
    l.insertatbegin(5);
    l.sh();
    l.insertatbegin(6);
    l.sh();
    l.insertatbegin(7);
    l.sh();
    l.reverseiteration();
    l.sh();
}
