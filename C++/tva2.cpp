
#include <iostream>
using namespace std ; 
class Node{
    public : 
    int data ; 
    Node* next ; 
    Node(int x){
        this->next= NULL ; 
        this->data = x ; 
    }

};
class CiruclarLinkedList{
    public : 
    Node* head ; 
    Node* last ; 
    CiruclarLinkedList(){
        this->head = NULL ; 
        this->last = NULL ;
    }
    void insertatbegining(int x){
        Node* newnode = new Node(x);
        if(head == NULL){
            head = newnode ; 
            last = newnode ; 
            last->next = head;
        }
        else{
            newnode->next = last->next;  
            last->next = newnode;
            head = newnode;

        }


    }
    void show(){
        Node* temp = head ;
        while(temp!=last){
            cout<<temp->data << " " ;
            temp = temp->next ;
        }
        cout << temp->data << " ";
        cout << endl ;

    }
    void insertanywhere(int x , int pos){
        Node* newnode = new Node(x);
        Node* temp = head ; 
        
        if(pos==1){
            newnode->next = head;
            head = newnode ; 
            last->next = head ; 
        }


        else{
            for(int i = 0 ; i < pos-2 ; i++){
                temp= temp->next ; 
            }
            newnode->next = temp->next ; 
            temp->next = newnode ; 
        }
    }
    void insertatend(int x){
        Node* newnode = new Node(x);
        newnode->next = last->next ; 
        last->next = newnode ; 
        last = newnode ; 
    }
    void deletebyposition(int pos){
        Node* temp = head ; 
        if(pos == 1){
            head = head->next ; 
            last->next = head ;
            temp->next = NULL ;

        }
        else {
        for(int i = 0 ; i < pos-2; i++){
            temp = temp->next ; 

        }
        Node* temp1 = temp->next ; 
        temp->next = temp1->next;
        temp1->next = NULL ; 
        }

    }
    void deletebyvalue(int x){
        Node* temp = head ; 
        if(searc(x) != -1){
            if(searc(x) == 1){
                head = head->next ; 
                temp->next = NULL ;

            }
            else{
                for(int i = 0  ; i < searc(x)-2 ; i++){
                    temp = temp->next ;


                }
                Node* temp1 = temp->next ;
                temp->next = temp1->next;
                temp1->next =NULL ;
            }
        }
        else{
            cout << "Value is not contained in the linked list ." << endl ; 
        }
    }

    int searc(int x){
        int p = 1 ; 
        Node* temp = head ; 
        while(temp!= NULL){
            if(temp->data == x){
                return p ; 
            }
            temp = temp->next ; 
            p++;
        }
        return -1 ; 

    }

    
};
int main(){
    CiruclarLinkedList l ;
    l.insertatbegining(4);
    l.show();
    l.insertatbegining(5);
    l.show();
    l.insertatend(9);
    l.show();
    l.insertanywhere(7,3);
    l.show();
    l.insertanywhere(65,1);
    l.show();
    l.insertanywhere(69,5);
    l.show();
    l.deletebyposition(4);
    l.show();





}