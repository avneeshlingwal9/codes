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
} ;
class linked_list{
    private : 
    Node* head ;
    public : 
    linked_list(){
        head = NULL ; 
    }
    void begininsert(int data ){
        Node* newnode = new Node(data);
            newnode->next = head ;
            head = newnode ; 
    
    }
    void insertanywh(int pos , int data ){
        Node* temp = new Node(data);
        if(head == NULL){
            temp = head ; 
            head = temp ; 

        }
        Node* temp1 = head ; 
        for(int i = 0 ; i < pos-2 ; i++){
            temp1 = temp1->next ;
        }

        temp->next = temp1->next ;
        temp1->next = temp ; 

    }
    void endinsrt(int data){
        Node* newnode = new Node(data);
        Node* temp = head ; 
        while(temp->next != NULL){
            temp = temp->next ; 
        }
        newnode->next = temp->next ;
        temp->next = newnode ; 
        
    }
    void dlet(int pos){
        Node* temp = head ; 
        for(int i = 0 ; i < pos-2 ; i++){
            temp = temp->next ; 
        }
        temp->next = temp->next->next ; 
        temp->next->next = NULL ;
    }
    int exst(int k){
        Node* temp = head ; 
        int in = 0 ; 
        while(temp!=NULL){
            if(temp->data == k){
                
                return in ; 
            }
            temp = temp->next;
            in++;
        }
        return -1 ; 
    }
    void dletkey(int k){
        Node* temp = head ; 
        Node* temp1 ; 
        int p = exst(k);
        if(p!= -1){
            if(p==1){
                head = temp->next;
                free(temp);
            }
            for(int i = 0 ; i < p-1 ; i++){
                temp= temp->next;
            }
            temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
            
        }
    
    }
    void sow(){
        cout << "The elements in the linked list are : - " ; 
        Node* temp = head ; 
        while(temp!= NULL){
            cout << temp->data << " " ;
            temp = temp->next ; 
        }
        cout << "\n"; 
    }

};
int main(){
    linked_list L ; 
    L.begininsert(5);
    L.sow();
    L.begininsert(4);
    L.sow();
    L.begininsert(3);
    L.sow();
    L.endinsrt(9);
    L.sow();
    L.insertanywh(1,78);
    L.sow();
    L.dletkey(9);
    L.sow();
    L.dletkey(20);
    L.sow();
    



}